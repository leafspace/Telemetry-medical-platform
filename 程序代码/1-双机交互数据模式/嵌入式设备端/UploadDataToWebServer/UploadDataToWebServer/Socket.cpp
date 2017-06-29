#include "Socket.h"

Socket::Socket(int PORT = 80, int BUFFER = 1024)
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
	//初始化Winsock
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Error : Winsock load failed !" << endl;
		return false;
	}

	//初始化套接字参数
	this->server.sin_family = AF_INET;
	this->server.sin_addr.s_addr = inet_addr(SERVERIP);
	this->server.sin_port = htons(this->PORT);

	//创建套接字
	this->client = socket(AF_INET, SOCK_STREAM, 0);
	if (this->client == INVALID_SOCKET) {
		cout << "Error : Socket failed (" << WSAGetLastError() << ") !" << endl;
		return false;
	}

	//连接服务器
	if (connect(client, (struct sockaddr*)&this->server, sizeof(this->server)) == INVALID_SOCKET) {
		cout << "Error : Connect failed (" << WSAGetLastError() << ") !" << endl;
		return false;
	}
	return true;
}

bool Socket::SendMessages(char* MSG)
{
	if (send(this->client, MSG, strlen(MSG), 0) == SOCKET_ERROR) {
		cout << "Error : Send msgs error (" << GetLastError() << ") !" << endl;
		return false;
	}

	return true;
}

char* Socket::ReceiveMessages()
{
	memset(buf, 0, sizeof(buf));
	int lenCode = recv(this->client, this->buf, sizeof(this->buf), 0);
	if (lenCode == SOCKET_ERROR) {
		return nullptr;
	}
	return this->buf;
}

void Socket::ClearConnection()
{
	closesocket(this->client);
	WSACleanup();
}
