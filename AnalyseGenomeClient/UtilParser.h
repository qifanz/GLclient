#pragma once
#include "Analyse.h"
#include <list>
#include "ClientSocket.h"

class UtilParser
{
public:
	UtilParser();
	~UtilParser();
	
	CString traiteMsgRecu(char* msg);
	CString prepareMsgAnalyse(Analyse a);
	CString prepareMsgListeMaladies();
	list<CString> returnListeMaladies();
	Analyse retournerAnalyse();
private: 
	CString version;
	
};

