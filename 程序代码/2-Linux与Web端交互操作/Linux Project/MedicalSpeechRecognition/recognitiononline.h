#ifndef RECOGNITIONONLINE_H
#define RECOGNITIONONLINE_H

#include <QStack>
#include "voice.h"
#include <stdio.h>
#include "xfMSC/qisr.h"
#include <QLatin1String>
#include "xfMSC/msp_cmn.h"
#include "xfMSC/msp_errors.h"

class RecognitionOnline
{
private:
    int grammar_id_len;
    char* login_params;
    char* grammar_id;
    char* result;
public:
    bool isLogin;
	QStack<QString> errorInfo;
    RecognitionOnline();
	bool doLogin(const char* username, const char* password);
	bool uploadData(const char* location, const char* mode);
	char* recognition(const char* location, const char* mode);

	char* getGrammarId();
	char* getTopResult();
	char* getResult();
};

#endif // RECOGNITIONONLINE_H
