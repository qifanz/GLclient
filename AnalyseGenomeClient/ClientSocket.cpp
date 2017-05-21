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
	Send("bonjour",BUFF_LEN);

	CAsyncSocket::OnConnect(nErrorCode);
}

/**
void ClientSocket::OnReceive(int nErrorCode)
{
	TRACE("Msg received: \r\n");
	
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);

	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize - 1] = '\0';
	TRACE(szBuff);
	AfxMessageBox(CString(szBuff));

	CAsyncSocket::OnReceive(nErrorCode);
}**/

void ClientSocket::receiveMsg()
{
	TRACE("Msg received: \r\n");

	char szBuff[BUFF_LEN];

	int nReceivedSize = recv(*this,szBuff, BUFF_LEN, 0);

	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize - 1] = '\0';
	TRACE(szBuff);
	AfxMessageBox(CString(szBuff));

	
}

void ClientSocket::sendMsg(const char* msg)
{
	Send(msg, BUFF_LEN,0);
}
