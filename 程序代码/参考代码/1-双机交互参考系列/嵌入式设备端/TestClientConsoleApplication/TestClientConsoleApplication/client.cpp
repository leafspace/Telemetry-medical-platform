#pragma  comment(lib,"ws2_32.lib")

#include <winsock.h>
#include <stdio.h>
#include <iostream>

#define  PORT 80
#define  BUFFER 1024


void main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET client;
	int port = PORT;


	int iLen;  //从服务器接收的数据长度
	char buf[BUFFER];


	struct sockaddr_in serv;//服务器端地址
	memset(buf, 0, sizeof(buf));//接收缓冲区初始化
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("winsock load failed\n");
		return;
	}


	//需要连接的服务器地址信息
	serv.sin_family = AF_INET;//需要连接的服务器的地址信息
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");//将命令行的IP地址转换为二进制表示的网络字节顺序IP地址
	serv.sin_port = htons(port);


	client = socket(AF_INET, SOCK_STREAM, 0);//建立客户端流套接字


	if (client == INVALID_SOCKET)
	{
		printf("socket() failed:%d\n", WSAGetLastError());
		return;
	}


	//请求与服务器建立TCP连接
	if (connect(client, (struct sockaddr*)&serv, sizeof(serv)) == INVALID_SOCKET)
	{
		printf("connect() failed:%d\n", WSAGetLastError());
		return;
	}
	else
	{
		int msgLen;
		unsigned long err;
		
		char msg[50];
		
		std::cin >> msg;
		if ((msgLen = send(client, msg, strlen(msg), 0)) == SOCKET_ERROR) {
			err = GetLastError();
			WSACleanup();
			printf("send mgs error. code ");
		}

		iLen = recv(client, buf, sizeof(buf), 0);
		if (iLen == 0)
		{
			return;
		}
		else if (iLen == SOCKET_ERROR)
		{
			printf("recv() failed:%s\n", WSAGetLastError());
			return;
		}
		printf("recv() data from server:%s\n", buf);
	}


	closesocket(client);
	WSACleanup();
	printf("press any key to continue");
	while (1);
}