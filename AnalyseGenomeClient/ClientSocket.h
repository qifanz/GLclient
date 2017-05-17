#pragma once
#include "Analyse.h"
#include <map>
#include <list>
// ClientSocket ÃüÁîÄ¿±ê

class ClientSocket : public CAsyncSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void sendMsg(CString msg);

private:
	Analyse resultAnalyse;
	//map<list<CString> maladies, CString server>> listeMaladies;
	bool responseReady;

};


