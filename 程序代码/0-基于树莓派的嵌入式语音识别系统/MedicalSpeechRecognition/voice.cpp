#include "voice.h"

int paragraph_voice;
QVector<ElemType*> speech_voice;                                               //用户说话的语音-以链的方式保存

bool OpenDrive(int *in)                                                        //打开硬件
{
	*in = ::open("/dev/audio1", O_RDONLY);                                     //audio1是设备中的新增喇叭文件-只读方式打开
	if (*in == -1) {
		return false;
	}
	return true;
}

bool OpenDrive(int *in, int *out)                                              //打开硬件
{
	*in = ::open("/dev/audio1", O_RDONLY);                                     //audio1是设备中的新增喇叭文件-只读方式打开
	*out = ::open("/dev/audio", O_WRONLY);                                     //audio是设备中的放音喇叭文件-只写方式打开

	if (*in == -1 || *out == -1) {
		return false;
	}
	return true;
}

int SetDrive(int *in)                                                          //设置硬件控制参数
{
	int arg;
	bool flag = true;
	int status;

	arg = SIZE;
	status = ioctl(*in, SOUND_PCM_WRITE_BITS, &arg);                           //设置设备采样位数
	if (status == -1) {
		return -1;
	}
	if (arg != SIZE) {
		status = false;
	}

	arg = CHANNELS;
	status = ioctl(*in, SOUND_PCM_WRITE_CHANNELS, &arg);                       //设置设备采样声道数
	if (status == -1) {
		return -1;
	}
	if (arg != CHANNELS) {
		status = false;
	}

	arg = RATE;
	status = ioctl(*in, SOUND_PCM_WRITE_RATE, &arg);                           //设置设备采样频率
	if (status == -1) {
		return -1;
	}
	if (arg != RATE) {
		status = false;
	}

	if (flag) {
		return 1;
	}
	else {
		return 0;
	}
}

int SetDrive(int *in, int *out)                                                //设置硬件控制参数
{
	int f_in = SetDrive(in);
	int f_out = SetDrive(out);

	if (f_in == -1 || f_out == -1) {
		return -1;
	}
	else if (f_in == 0 || f_out == 0) {
		return 0;
	}
	else {
		return 1;
	}

}
