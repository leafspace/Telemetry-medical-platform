#include <QStack>
#include "voice.h"
#include "xfMSC/qisr.h"
#include "xfMSC/msp_cmn.h"
#include "xfMSC/msp_errors.h"

class RecognitionOnline
{
private:
    int grammar_id_len;                                                        //标识语义的grammar_id长度
    char* login_params;                                                        //登陆的相关参数
    char* grammar_id;                                                          //标识上传语义的ID
    char* result;                                                              //识别结果
public:
    bool isLogin;                                                              //表示是否已经登陆到讯飞
	QStack<QString> errorInfo;                                                 //识别过程中的错误栈
    RecognitionOnline();
	bool doLogin(const char* username, const char* password);                  //登陆操作
	bool uploadData(const char* location, const char* mode);                   //上传语义
	char* recognition(const char* location, const char* mode);                 //识别过程

	char* getGrammarId();                                                      //获取grammar_id
	char* getTopResult();                                                      //获取识别度最高的识别结果
	char* getResult();                                                         //获取识别的所有结果（包括相关格式）
};
