#ifndef READAUDIO_H
#define READAUDIO_H

#include "voice.h"
#include <QThread>

class ReadAudio :public QThread                                                //读取喇叭语音数据-线程
{
	Q_OBJECT
public:
	ReadAudio();
	void setAudio(int in);                                                     //设置读取文件的ID
	void stop();

protected:
	int audio_fp;                                                              //喇叭硬件文件ID
	void run();                                                                //读取语音数据操作

private:
	volatile bool stopped;
};

#endif // READAUDIO_H
