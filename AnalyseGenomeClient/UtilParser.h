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
	const char* prepareMsgListeMaladies();
	list<CString> returnListeMaladies();
	Analyse retournerAnalyse();
private: 
	CString version;
	
};

