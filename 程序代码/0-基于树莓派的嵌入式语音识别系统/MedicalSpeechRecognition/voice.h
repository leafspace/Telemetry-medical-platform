#ifndef VOICE_H
#define VOICE_H

#include <QVector>
#include <fcntl.h>                                                             //linux中对于硬件文件的操作支持
#include <unistd.h>                                                            //linux中对于硬件文件的操作支持
#include <sys/stat.h>                                                          //linux中对于硬件文件的操作支持
#include <sys/ioctl.h>                                                         //linux中对于硬件文件的操作支持
#include <sys/types.h>                                                         //linux中对于硬件文件的操作支持
#include <sys/soundcard.h>                                                     //linux中对于声卡文件的操作支持

#define SIZE 16                                                                //采样位数
#define RATE 16000                                                             //采样频率
#define CHANNELS 1                                                             //声道数
#define BUFSIZE 1600                                                           //（讯飞）单位上传的数据个数
#define GRAPH_SPEED 100                                                        //图像刷新的时间

typedef short ElemType;                                                        //随着SIZE的变化而变化  /* SIZE       type 8          char 16         short 32         int 64         long */
typedef struct Wav_file
{
	char id_RIFF[4];                                                           //RIFF块标志
	int fileSize;                                                              //文件的总字节数
	char id_WAVE[4];                                                           //WAV标志

	char id_FMT[4];                                                            //格式块标志
	int formatLength;                                                          //格式块长度，16为正常，18说明有附加信息
	short int formatTag;                                                       //格式类别，值=1 表示编码方式为PCMu律编码
	short int channelsNumber;                                                  //声道数
	int sampleRate;                                                            //每秒的样本数
	int secondBytes;                                                           //每秒数据的字节数
	short int chunkAlign;                                                      //采样字节数
	short int sampleBits;                                                      //采样位数

	char id_DATA[5];                                                           //附加块标志
	int dataSize;                                                              //数据部分字节数
}Wav_file;

extern int paragraph_voice;
extern QVector<ElemType*> speech_voice;                                        //用户说话的语音-以链的方式保存

bool OpenDrive(int *in);                                                       //打开硬件
bool OpenDrive(int *in, int *out);                                             //打开硬件

int SetDrive(int *in);                                                         //设置硬件控制参数
int SetDrive(int *in, int *out);                                               //设置硬件控制参数

#endif // VOICE_H

