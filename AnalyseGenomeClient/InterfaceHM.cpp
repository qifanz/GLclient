#include "stdafx.h"
#include <string>
#include <map>
#include <list>
#include "InterfaceHM.h"

using namespace std;


InterfaceHM::InterfaceHM()
{
	version="1.0";
}
InterfaceHM::~InterfaceHM()
{
}


void InterfaceHM::startConnection()
{
	clientSocket.Create();
	clientSocket.Connect(CString("127.0.0.1"), 8080);
}

void InterfaceHM::disconnect()
{
	clientSocket.Close();
}

void InterfaceHM::demanderAnalyseGenerale(Analyse analyse) {
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
}

void InterfaceHM::demanderAnalyseCiblee(Analyse analyse, string maladie) {
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse,maladie));
}



void InterfaceHM::listerMaladies() {
	clientSocket.sendMsg(parser.prepareMsgListeMaladies());
	
}
void InterfaceHM::receive() {
	clientSocket.receiveMsg();
}





