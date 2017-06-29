#include "uploadingresult.h"
#include <QtGui>
UploadingResult::UploadingResult()
{
	stopped = false;
}

void UploadingResult::setSocket(Socket socket)
{
    this->client = socket;
}

void UploadingResult::run()
{
	if (!stopped) {
        while(true) {
            while(messageQueue.IsEmpty() == false){
                MessageToServer *message = messageQueue.PopMessage();
                this->client.SendMessages(message->getInformation());
            }
        }
		stopped = true;
	}
}

void UploadingResult::stop()
{
	stopped = true;
}
