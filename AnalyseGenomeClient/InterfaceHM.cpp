#include "stdafx.h"
#include <string>
#include <map>
#include <list>
#include "InterfaceHM.h"

using namespace std;


InterfaceHM::InterfaceHM()
{

}
InterfaceHM::~InterfaceHM()
{
}


void InterfaceHM::startConnection()
{
	clientSocket.Create();
	clientSocket.Connect(CString("127.0.0.1"), 8080);
}

void InterfaceHM::demanderAnalyseGenerale(Analyse analyse) {
	UtilParser parser;
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
}

void InterfaceHM::demanderAnalyseCiblee(Analyse analyse, string maladie) {
	UtilParser parser;
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
}



void InterfaceHM::listerMaladies() {
	UtilParser parser;
	clientSocket.sendMsg(parser.prepareMsgListeMaladies());
	
}





