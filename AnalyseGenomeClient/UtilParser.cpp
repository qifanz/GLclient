#include "stdafx.h"
#include "UtilParser.h"
#include "ClientSocket.h"


UtilParser::UtilParser()
{
	version = "MA v1.0";
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
	//msgToSend += "MA v";
	msgToSend += version;
	msgToSend += "\r\n";
	msgToSend += "CHECK ALL\r\n";
	Genome genome = a.getGenome();
	for (auto it : genome.getMots())
	{
		msgToSend += it;
		msgToSend += ";";
		
	}
	msgToSend += "\r\n";
	TRACE (msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg,msgToSend.c_str());
	return (msg);
}
const char* UtilParser::prepareMsgAnalyse(Analyse a,string maladie)
{
	TRACE("preparing \r\n");
	string msgToSend;
	//msgToSend += "MA v";
	msgToSend += version;
	msgToSend += "\r\nCHECK DISEASE\r\n";
	msgToSend += maladie;
	msgToSend += "\r\n";
	Genome genome = a.getGenome();
	for (auto it : genome.getMots())
	{
		msgToSend += it;
		msgToSend += ";";

	}
	msgToSend += "\r\n";
	TRACE(msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg, msgToSend.c_str());
	return (msg);
}

const char* UtilParser::prepareMsgListeMaladies()
{
	string msgToSend;
//	msgToSend += "MA v";
	msgToSend += version;
	msgToSend+="\r\nGET DISEASES\r\n\r\n";
	TRACE(msgToSend.c_str());
	char msg[BUFF_LEN];
	strcpy_s(msg, msgToSend.c_str());
	return (msg);
}

list<string> UtilParser::returnListeMaladies()
{
	return list<string>();
}

Analyse UtilParser::retournerAnalyse()
{
	return Analyse(Genome("123"),"123");
}
