#include "stdafx.h"
#include "UtilParser.h"
#include "ClientSocket.h"


UtilParser::UtilParser()
{
}


UtilParser::~UtilParser()
{
}




char* UtilParser::traiteMsgRecu(char * msg)
{
	TRACE(msg);
	return (("test"));
}

const char* UtilParser::prepareMsgAnalyse(Analyse a)
{
	TRACE("preparing \r\n");
	string msgToSend;
	msgToSend += "MA v1.0/r/n";
	msgToSend += "CHECK DISEASE\r\n";
	msgToSend += a.getType();
	msgToSend += "\r\n";



	Genome genome = a.getGenome();
	for (auto it : genome.mots)
	{
		msgToSend += it;
		msgToSend += "\r\n";
		TRACE(it.c_str());
	}
	
	return (msgToSend.c_str());
}

const char* UtilParser::prepareMsgListeMaladies()
{
	return ( ("prepareMsgListeMaladies"));
}

list<CString> UtilParser::returnListeMaladies()
{
	return list<CString>();
}

Analyse UtilParser::retournerAnalyse()
{
	return Analyse(Genome("123"),"123","123");
}
