#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "readaudio.h"
#include "playaudio.h"
#include <QMainWindow>
#include "recognitiononline.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	Ui::MainWindow *ui;

	void paintEvent(QPaintEvent*);                                             //重绘函数-用户嵌入式设备全屏使用
	QPainter *paint;
	bool control_state;                                                        //标识当前是否处于录完音状态
	int voice_fp;                                                              //录音文件ID
	int play_fp;                                                               //播放文件ID

	bool drive_ready;                                                          //标识设备是否已经准备完成
	ReadAudio readThread;                                                      //录音线程
	PlayAudio playThread;                                                      //播放线程
	RecognitionOnline recognitiononlineThread;                                 //识别线程

	bool connectDrive();                                                       //连接设备
	void createVoice();                                                        //创建语音
	public slots:
	void ClickButton_Conc();                                                   //连接硬件按钮响应函数
	void ClickButton_Start();                                                  //开始录音按钮响应函数
	void ClickButton_Stop();                                                   //停止录音按钮响应函数
	void ClickButton_Play();                                                   //播放录音按钮响应函数
	void ClickButton_Reco();                                                   //识别录音按钮响应函数
};

#endif // MAINWINDOW_H
