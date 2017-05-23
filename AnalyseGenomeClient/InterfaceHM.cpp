#include "stdafx.h"
#include <string>
#include <map>
#include <list>
#include "InterfaceHM.h"

using namespace std;


InterfaceHM::InterfaceHM()
{
	version = "1.0";
}
InterfaceHM::~InterfaceHM()
{
}
void InterfaceHM::demanderAnalyseGenerale(Analyse analyse) {
	for (auto s : serveurs)
	{
		clientSocket.Create();
		clientSocket.Connect(CString(s.getAddr().c_str()), s.getPort());

		int returncode = clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
		if (returncode!=-1) {
			AfxMessageBox(CString(clientSocket.receiveMsg()));
		}
		clientSocket.Close();
	}

}

void InterfaceHM::demanderAnalyseCiblee(Analyse analyse, string maladie) {
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse, maladie));
	AfxMessageBox(CString(clientSocket.receiveMsg()));
}


void InterfaceHM::demanderListerMaladies() {
	for (auto s : serveurs)
	{
		clientSocket.Create();
		clientSocket.Connect(CString(s.getAddr().c_str()), s.getPort());
		int returncode = clientSocket.sendMsg(parser.prepareMsgListeMaladies());
		if (returncode!=-1) {
			list<string> maladies = parser.parseListeMaladies(clientSocket.receiveMsg());
			for (auto m : maladies)
			{
				listeMaladies.insert(pair<string, Server>(m, s));
			}
		}
		clientSocket.Close();
	}
}

void InterfaceHM::afficherResultatListeMaladies()
{

	//pour afficher
	set<string> afficheMaladie;
	for (auto mm : listeMaladies)
	{
		afficheMaladie.insert(mm.first);
	}
	string toShow="Les maladies disponibles pour analyser sont suivantes:\r\n\r\n";
	for (auto a : afficheMaladie)
	{
		toShow += a;
		toShow += "\r\n";
	}
	AfxMessageBox(CString(toShow.c_str()));
}

void InterfaceHM::initialise()
{
	serveurs.push_back(Server("127.0.0.1", 8080));
	serveurs.push_back(Server("127.0.0.1", 8085));
	serveurs.push_back(Server("127.0.0.1", 8090));
}

void InterfaceHM::logger(char * msg)
{
}






