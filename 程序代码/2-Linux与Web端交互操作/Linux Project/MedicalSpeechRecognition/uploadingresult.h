#ifndef UPLOADINGRESULT_H
#define UPLOADINGRESULT_H

#include "voice.h"
#include <QThread>

class UploadingResult :public QThread
{
	Q_OBJECT
public:
	UploadingResult();
    void setSocket(Socket socket);
	void stop();

protected:
    Socket client;
	void run();

private:
	volatile bool stopped;
};

#endif // UPLOADINGRESULT_H
