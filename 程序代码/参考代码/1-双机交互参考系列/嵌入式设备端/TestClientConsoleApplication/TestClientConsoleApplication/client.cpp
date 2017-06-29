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


	int iLen;  //�ӷ��������յ����ݳ���
	char buf[BUFFER];


	struct sockaddr_in serv;//�������˵�ַ
	memset(buf, 0, sizeof(buf));//���ջ�������ʼ��
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("winsock load failed\n");
		return;
	}


	//��Ҫ���ӵķ�������ַ��Ϣ
	serv.sin_family = AF_INET;//��Ҫ���ӵķ������ĵ�ַ��Ϣ
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");//�������е�IP��ַת��Ϊ�����Ʊ�ʾ�������ֽ�˳��IP��ַ
	serv.sin_port = htons(port);


	client = socket(AF_INET, SOCK_STREAM, 0);//�����ͻ������׽���


	if (client == INVALID_SOCKET)
	{
		printf("socket() failed:%d\n", WSAGetLastError());
		return;
	}


	//���������������TCP����
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