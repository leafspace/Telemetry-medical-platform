#ifndef PLAYAUDIO_H
#define PLAYAUDIO_H

#include "voice.h"
#include <QThread>

class PlayAudio :public QThread                                                //输出喇叭语音数据-线程
{
	Q_OBJECT
public:
	PlayAudio();
	void setAudio(int out);                                                    //设置输出文件ID
	void stop();

protected:
	int audio_fp;                                                              //硬件ID
	void run();                                                                //播放语音数据

private:
	volatile bool stopped;
};

#endif // PLAYAUDIO_H
