// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "AnalyseGenomeClient.h"
#include "ClientSocket.h"


// ClientSocket

ClientSocket::ClientSocket()
{
	
}

ClientSocket::~ClientSocket()
{
}


// ClientSocket 成员函数


void ClientSocket::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	//Send("bonjour",BUFF_LEN);

	CAsyncSocket::OnConnect(nErrorCode);
}



char* ClientSocket::receiveMsg()
{
	char *szBuff=new char[2048];
	int nReceivedSize = 0;
	while (true)
	{
		 nReceivedSize = recv(*this, szBuff, BUFF_LEN, 0);
		if (nReceivedSize >0 )
			break;
		Sleep(100);
	}

	szBuff[nReceivedSize - 1] = '\0';

	return szBuff;

	
}

void ClientSocket::sendMsg(const char* msg)
{
	Send(msg, BUFF_LEN,0);
}
