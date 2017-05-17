#pragma once
class InterfceClient
{
public:
	InterfceClient();
	~InterfceClient();
	void creerMedecinSocket();
	void traiteMsgRecu(char* msg);
	void prepareMsgAnalyse(Analyse a);




private:
	CString version;
};

