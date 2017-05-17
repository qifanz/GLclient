#include "stdafx.h"
#include "UtilParser.h"
#include "ClientSocket.h"


UtilParser::UtilParser()
{
}


UtilParser::~UtilParser()
{
}




CString UtilParser::traiteMsgRecu(char * msg)
{
	TRACE(msg);
}

CString UtilParser::prepareMsgAnalyse(Analyse a)
{
	
}

CString UtilParser::prepareMsgListeMaladies()
{
}

list<CString> UtilParser::returnListeMaladies()
{
	return list<CString>();
}

Analyse UtilParser::retournerAnalyse()
{
	return Analyse(Genome("123"),"123","123");
}
