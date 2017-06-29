#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>                                                           //用于支持socket操作
#include <netinet/in.h>

class Socket
{
private:
	int PORT;
	int BUFFER;

	sockaddr_in server;
    int client;
	char* buf;

	void ClearConnection();
public:
    Socket();
	Socket(int, int);
	~Socket();
	bool ConnectToServer(char* SERVERIP);
	bool SendMessages(char* MSG);
	char* ReceiveMessages();
};

#endif // SOCKET_H
