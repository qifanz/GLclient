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

list<string> UtilParser::parseListeMaladies(char* msg)
{
	list<string> maladie;
	string msgRecu(msg);
	//AfxMessageBox(CString(msgRecu.c_str()));
	int pos = msgRecu.find("\r\n");
	pos = msgRecu.find("\r\n", pos+1);
	int pos1 = 0;
	while (true)
	{
		pos1 = msgRecu.find("\r\n", pos+1);
		string temp = msgRecu.substr(pos + 2, pos1 - pos - 2);
		//AfxMessageBox(CString(temp.c_str()));
		pos = pos1;
		if (temp == "") {
			break;
		}
		maladie.push_back(temp);
		TRACE("disease found %s\r\n", temp.c_str());
	}
	return maladie;
}

Analyse* UtilParser::parseResultatCiblee(char * msg)
{
	Analyse *a = new Analyse;
	return new Analyse;
}

Analyse* UtilParser::parseResultatGeneral(char * msg)
{
	return new Analyse;
}


