#pragma once
#include "Analyse.h"
#include <map>
#include <list>
// ClientSocket ����Ŀ��

class ClientSocket : public CAsyncSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void sendMsg(const char* msg);
	const static int BUFF_LEN = 2048;
private:
	Analyse resultAnalyse;
	//map<list<CString> maladies, CString server>> listeMaladies;
	bool responseReady;

};


