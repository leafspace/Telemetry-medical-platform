#include "socket.h"

Socket::Socket()
{
    this->PORT = 10212;
    this->BUFFER = 1024;

    this->buf = new char[this->BUFFER];
}

Socket::Socket(int PORT = 10212, int BUFFER = 1024)
{
	this->PORT = PORT;
	this->BUFFER = BUFFER;

	this->buf = new char[this->BUFFER];
}

Socket::~Socket()
{
	delete this->buf;
	this->ClearConnection();
}

bool Socket::ConnectToServer(char * SERVERIP)
{
	//初始化套接字参数
	this->server.sin_family = AF_INET;
	this->server.sin_port = htons(this->PORT);
    if(inet_pton(AF_INET, SERVERIP, &this->server.sin_addr) <= 0) {
        return false;
    }

	//创建套接字
	this->client = socket(AF_INET, SOCK_STREAM, 0);
    if (this->client < 0) {
		return false;
	}

	//连接服务器
    if (connect(client, (struct sockaddr*)&this->server, sizeof(this->server)) < 0) {
		return false;
	}
	return true;
}

bool Socket::SendMessages(char* MSG)
{
    if (send(this->client, MSG, strlen(MSG), 0) < 0) {
		return false;
	}

	return true;
}

char* Socket::ReceiveMessages()
{
	memset(buf, 0, sizeof(buf));
	int lenCode = recv(this->client, this->buf, sizeof(this->buf), 0);
    if (lenCode == -1) {
        return NULL;
	}
	return this->buf;
}

void Socket::ClearConnection()
{
    close(this->client);
}
