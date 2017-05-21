#pragma once
#include "Analyse.h"
#include <list>
#include "ClientSocket.h"

class UtilParser
{
public:
	UtilParser();
	~UtilParser();
	
	char* traiteMsgRecu(char* msg);
	const char* prepareMsgAnalyse(Analyse a);
	const char* prepareMsgAnalyse(Analyse a,string maladie);
	const char* prepareMsgListeMaladies();
	list<string> returnListeMaladies();
	Analyse retournerAnalyse();
	const static int BUFF_LEN = 2048;

private: 
	string version;
	
};

