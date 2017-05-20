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
	msgToSend += "CHECK ALL\r\n";
	Genome genome = a.getGenome();
	for (auto it : genome.mots)
	{
		msgToSend += it;
		msgToSend += "\r\n";
		
	}
	TRACE (msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg,msgToSend.c_str());
	return (msg);
}
const char* UtilParser::prepareMsgAnalyse(Analyse a,string maladie)
{
	TRACE("preparing \r\n");
	string msgToSend;
	msgToSend += "MA v1.0/r/n";
	msgToSend += "CHECK DISEASE\r\n";
	msgToSend += maladie;
	msgToSend += "\r\n";
	Genome genome = a.getGenome();
	for (auto it : genome.mots)
	{
		msgToSend += it;
		msgToSend += "\r\n";

	}
	TRACE(msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg, msgToSend.c_str());
	return (msg);
}

const char* UtilParser::prepareMsgListeMaladies()
{
	string msgToSend;
	msgToSend += "MA v1.0\r\nGET DISEASES\r\n\r\n";
	TRACE(msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg, msgToSend.c_str());
	return (msg);
}

list<CString> UtilParser::returnListeMaladies()
{
	return list<CString>();
}

Analyse UtilParser::retournerAnalyse()
{
	return Analyse(Genome("123"),"123","123");
}
