// ClientSocket.cpp : ʵ���ļ�
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


// ClientSocket ��Ա����


void ClientSocket::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	Send("bonjour",2048);

	CAsyncSocket::OnConnect(nErrorCode);
}


void ClientSocket::OnReceive(int nErrorCode)
{
	TRACE("Msg received: \r\n");
	const int BUFF_LEN = 2048;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);

	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize - 1] = '\0';
	TRACE(szBuff);

	CAsyncSocket::OnReceive(nErrorCode);
}

void ClientSocket::sendMsg(const char* msg)
{
	Send(msg, 2048);
}
