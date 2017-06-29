#include "Socket.h"
#include "MessageToServer.h"

int main()
{
	Socket client(80, 1024);
	client.ConnectToServer("127.0.0.1");
	MessageQueue *queue = new MessageQueue();


	char* str = new char[50];
	cin >> str;
	MessageToServer msg(true, str);
	queue->PushMessage(msg);

	if (!(queue->IsEmpty())) {
		MessageToServer *mts = queue->PopMessage();
		client.SendMessages(mts->toString());
	}

	return 0;
}