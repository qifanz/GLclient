#pragma once
#include "Analyse.h"
#include <map>
#include <list>
// ClientSocket ÃüÁîÄ¿±ê

class ClientSocket : public CSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnConnect(int nErrorCode);
	char* receiveMsg();

	int sendMsg(const char* msg);
	const static int BUFF_LEN = 2048;
private:

};


