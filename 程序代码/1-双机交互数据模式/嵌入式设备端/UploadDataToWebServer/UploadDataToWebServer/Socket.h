#pragma once
#pragma comment(lib,"ws2_32.lib")
#include <iostream>
#include <winsock.h>                                                           //用于支持socket操作
#include <string>
using namespace std;

class Socket
{
private:
	int PORT;
	int BUFFER;

	sockaddr_in server;
	SOCKET client;
	char* buf;

	void ClearConnection();
public:
	Socket(int, int);
	~Socket();
	bool ConnectToServer(char* SERVERIP);
	bool SendMessages(char* MSG);
	char* ReceiveMessages();
};
