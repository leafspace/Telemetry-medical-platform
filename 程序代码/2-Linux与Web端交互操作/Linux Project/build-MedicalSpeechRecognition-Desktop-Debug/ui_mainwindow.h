/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <graph.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_y;
    QLabel *label_x;
    QTextBrowser *textBrowser_resu;
    QLabel *label_text;
    Graph *graph;
    QLabel *label_graph;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;
    QPushButton *pushButton_reco;
    QPushButton *pushButton_conc;
    QLabel *label_grammar;
    QTextBrowser *textBrowser_gram;
    QLabel *label_supt;
    QPushButton *pushButton_exit;
    QLabel *label_ip;
    QTextEdit *textEdit_ip;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 557);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_y = new QLabel(centralWidget);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setGeometry(QRect(20, 240, 17, 17));
        label_x = new QLabel(centralWidget);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setGeometry(QRect(260, 465, 17, 17));
        textBrowser_resu = new QTextBrowser(centralWidget);
        textBrowser_resu->setObjectName(QString::fromUtf8("textBrowser_resu"));
        textBrowser_resu->setGeometry(QRect(540, 190, 221, 101));
        label_text = new QLabel(centralWidget);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setGeometry(QRect(550, 160, 131, 17));
        graph = new Graph(centralWidget);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setEnabled(true);
        graph->setGeometry(QRect(40, 39, 470, 421));
        label_graph = new QLabel(centralWidget);
        label_graph->setObjectName(QString::fromUtf8("label_graph"));
        label_graph->setGeometry(QRect(50, 10, 91, 17));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(540, 360, 99, 27));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(540, 410, 99, 27));
        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(660, 330, 99, 27));
        pushButton_reco = new QPushButton(centralWidget);
        pushButton_reco->setObjectName(QString::fromUtf8("pushButton_reco"));
        pushButton_reco->setGeometry(QRect(660, 380, 99, 27));
        pushButton_conc = new QPushButton(centralWidget);
        pushButton_conc->setObjectName(QString::fromUtf8("pushButton_conc"));
        pushButton_conc->setGeometry(QRect(540, 310, 99, 27));
        label_grammar = new QLabel(centralWidget);
        label_grammar->setObjectName(QString::fromUtf8("label_grammar"));
        label_grammar->setGeometry(QRect(550, 70, 81, 17));
        textBrowser_gram = new QTextBrowser(centralWidget);
        textBrowser_gram->setObjectName(QString::fromUtf8("textBrowser_gram"));
        textBrowser_gram->setGeometry(QRect(540, 100, 221, 41));
        textBrowser_gram->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label_supt = new QLabel(centralWidget);
        label_supt->setObjectName(QString::fromUtf8("label_supt"));
        label_supt->setGeometry(QRect(620, 490, 171, 21));
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(660, 430, 99, 27));
        label_ip = new QLabel(centralWidget);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(550, 10, 67, 17));
        textEdit_ip = new QTextEdit(centralWidget);
        textEdit_ip->setObjectName(QString::fromUtf8("textEdit_ip"));
        textEdit_ip->setGeometry(QRect(540, 30, 221, 21));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 31));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Medical Speech Recognition Demo", 0, QApplication::UnicodeUTF8));
        label_y->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_x->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_text->setText(QApplication::translate("MainWindow", "Recognition result", 0, QApplication::UnicodeUTF8));
        label_graph->setText(QApplication::translate("MainWindow", "Speech graph", 0, QApplication::UnicodeUTF8));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_reco->setText(QApplication::translate("MainWindow", "Recognition", 0, QApplication::UnicodeUTF8));
        pushButton_conc->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label_grammar->setText(QApplication::translate("MainWindow", "Grammar id", 0, QApplication::UnicodeUTF8));
        label_supt->setText(QString());
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label_ip->setText(QApplication::translate("MainWindow", "Server ip", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
