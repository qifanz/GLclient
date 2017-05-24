#pragma once
#include "Analyse.h"
#include <list>
#include "ClientSocket.h"

class UtilParser
{
public:
	UtilParser();
	~UtilParser();
	

	const char* prepareMsgAnalyse(Analyse a);
	const char* prepareMsgAnalyse(Analyse a,string maladie);
	const char* prepareMsgListeMaladies();
	list<string> parseListeMaladies(char* msg);
	Analyse* parseResultatCiblee(char* msg);
	Analyse* parseResultatGeneral(char* msg);
	string getVersion();
	const static int BUFF_LEN = 2048;

private: 
	string version;
	
};

