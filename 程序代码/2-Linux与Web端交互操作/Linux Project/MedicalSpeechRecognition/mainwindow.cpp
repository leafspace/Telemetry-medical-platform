﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#define	BUFFER_SIZE 2048
#define HINTS_SIZE  100
#define GRAMID_LEN	128
#define FRAME_LEN	640

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->pushButton_conc, SIGNAL(clicked()), this, SLOT(ClickButton_Conc()));
	connect(ui->pushButton_start, SIGNAL(clicked()), this, SLOT(ClickButton_Start()));
	connect(ui->pushButton_stop, SIGNAL(clicked()), this, SLOT(ClickButton_Stop()));
	connect(ui->pushButton_play, SIGNAL(clicked()), this, SLOT(ClickButton_Play()));
	connect(ui->pushButton_reco, SIGNAL(clicked()), this, SLOT(ClickButton_Reco()));
	connect(ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(ClickButton_Exit()));
	control_state = false;
	paragraph_voice = 0;
	drive_ready = false;

    ui->textEdit_ip->setText("10.16.16.114");
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
}

MainWindow::~MainWindow()
{
    //uploadThread.stop();
	::close(voice_fp);
	::close(play_fp);

	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

}

bool MainWindow::connectDrive()
{
    QString edit_ip = ui->textEdit_ip->toPlainText();
    serverIP = edit_ip.toLatin1().data();

    if(client.ConnectToServer(serverIP) == false) {
        QMessageBox::critical(this, tr("Error"), tr("Socket Connected failed !"), QMessageBox::Yes);
        return false;
    }

	int status;
	if (OpenDrive(&voice_fp, &play_fp) == false) {
		QMessageBox::critical(this, tr("Error"), tr("File open failed !"), QMessageBox::Yes);
		return false;
	}

	if ((status = SetDrive(&voice_fp, &play_fp)) == -1) {
		QMessageBox::critical(this, tr("Error"), tr("File set failed !"), QMessageBox::Yes);
		return false;
	}
	else if (status == 0) {
		QMessageBox::StandardButton rebutton =
			QMessageBox::warning(this, tr("Warning"), tr("Some set defferent !"), QMessageBox::Yes | QMessageBox::Ignore);
		if (rebutton == QMessageBox::Yes) {
			return false;
		}
	}

	readThread.setAudio(voice_fp);
	playThread.setAudio(play_fp);
    //uploadThread.setSocket(client);
	return true;
}

void MainWindow::createVoice()
{
	int dataLen = speech_voice.size() * BUFSIZE * sizeof(ElemType);
	Wav_file default_wavfile = {
		{ 'R', 'I', 'F', 'F' },
		dataLen + sizeof(Wav_file) - 8,
		{'W', 'A', 'V', 'E'},
		{'f', 'm', 't', ' '},
		16,
		1,
		CHANNELS,
		RATE,
		RATE * SIZE / 8,
		SIZE / 8,
		SIZE,
		{'d', 'a', 't', 'a'},
		dataLen
	};

	FILE* fp = NULL;
	if ((fp = fopen("wav/upload.wav", "wb")) == NULL) {
		QMessageBox::critical(this, tr("Error"), tr("File open failed !"), QMessageBox::Yes);
		return;
	}
	fwrite(&default_wavfile, sizeof(Wav_file), 1, fp);
	int temp = dataLen + sizeof(Wav_file) - 8;
	fseek(fp, 4, 0);
	fwrite(&temp, sizeof(int), 1, fp);
	fseek(fp, 40, 0);
	fwrite(&dataLen, sizeof(int), 1, fp);
    for (int i = 0; i < speech_voice.size(); ++i) {
		fwrite(speech_voice[i], BUFSIZE * sizeof(ElemType), 1, fp);
	}
	fclose(fp);
}

void MainWindow::ClickButton_Conc()
{
	if (connectDrive()) {
		ui->pushButton_conc->setEnabled(false);
		drive_ready = true;
	}
	else {
		drive_ready = false;
	}
}

void MainWindow::ClickButton_Start()
{
	if (!drive_ready) {
		QMessageBox::warning(this, tr("Warning"), tr("You should connect the audio !"), QMessageBox::Yes);
		return;
	}
	if (control_state == true) {
		return;
	}
	ui->graph->startTime(GRAPH_SPEED);
	readThread.start();
    //uploadThread.start();
	control_state = true;
}

void MainWindow::ClickButton_Stop()
{
	if (!drive_ready) {
		QMessageBox::warning(this, tr("Warning"), tr("You should connect the audio !"), QMessageBox::Yes);
		return;
	}
	if (control_state == false) {
		return;
	}
	readThread.stop();
	ui->graph->stopTime();
	control_state = false;

    createVoice();
}

void MainWindow::ClickButton_Play()
{
	if (!drive_ready) {
		QMessageBox::warning(this, tr("Warning"), tr("You should connect the audio !"), QMessageBox::Yes);
		return;
	}
	playThread.start();
}

void MainWindow::ClickButton_Reco()
{
	if (!drive_ready) {
		QMessageBox::warning(this, tr("Warning"), tr("You should connect the audio !"), QMessageBox::Yes);
		return;
	}

	bool reco_f = true;
	char* result = NULL;

    if (recognitiononlineThread.isLogin == false) {
		if ((reco_f = recognitiononlineThread.doLogin(NULL, NULL)) == false) {
			while (!recognitiononlineThread.errorInfo.empty()) {
				QMessageBox::critical(this, tr("Error"), recognitiononlineThread.errorInfo.pop(), QMessageBox::Yes);
			}
			return;
		}
    }

    if ((reco_f = recognitiononlineThread.uploadData("prammar.abnf", "dtt = abnf, sub = asr")) == false) {
        while (!recognitiononlineThread.errorInfo.empty()) {
            QMessageBox::critical(this, tr("Error"), recognitiononlineThread.errorInfo.pop(), QMessageBox::Yes);
        }
        return;
    }
    else {
        ui->textBrowser_gram->clear();
        ui->textBrowser_gram->append(recognitiononlineThread.getGrammarId());
    }


    result = recognitiononlineThread.recognition("wav/upload.wav", "sub = asr, result_type = plain, result_encoding = utf8");
    if (result == NULL) {
		while (!recognitiononlineThread.errorInfo.empty()) {
			QMessageBox::critical(this, tr("Error"), recognitiononlineThread.errorInfo.pop(), QMessageBox::Yes);
		}
		return;
	}

    if(strlen(result) == 0){
        ui->textBrowser_resu->clear();
        ui->textBrowser_resu->append("No Resault!");
    }else{
        ui->textBrowser_resu->clear();
        ui->textBrowser_resu->append(recognitiononlineThread.getTopResult());
        //ui->textBrowser_resu->append(result);

		MessageToServer msg(true, result);
        /*
        if(this->client.SendMessages(result) == false) {
            QMessageBox::critical(this, tr("Error"), tr("Send message error !"), QMessageBox::Yes);
        }
        */
        if(this->client.SendMessages(recognitiononlineThread.getTopResult()) == false) {
            QMessageBox::critical(this, tr("Error"), tr("Send message error !"), QMessageBox::Yes);
        }
        //messageQueue.PushMessage(msg);
    }
}

void MainWindow::ClickButton_Exit()
{
    this->close();
}
