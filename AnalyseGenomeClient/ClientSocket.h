#pragma once

// ClientSocket ����Ŀ��

class ClientSocket : public CAsyncSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void sendMsg(CString msg);
};


