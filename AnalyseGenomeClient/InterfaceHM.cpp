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
	map<string, bool> result;
	for (auto s : serveurs)
	{
		clientSocket.Create();
		clientSocket.Connect(CString(s.getAddr().c_str()), s.getPort());

		int returncode = clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
		if (returncode!=-1) {
			Analyse* a = parser.parseResultatGeneral(clientSocket.receiveMsg());
			for (auto res : a->getResults())
			{
			
				result.insert(res);
			}
			//AfxMessageBox(CString(clientSocket.receiveMsg()));
		}
		
		clientSocket.Close();
	}
	afficherResultatAnalyse(result);
}

void InterfaceHM::demanderAnalyseCiblee(Analyse analyse, string maladie) {
	map<string, bool> result;
	multimap<string, Server>::iterator it = listeMaladies.find(maladie);
	int counter = listeMaladies.count(maladie);
	if (listeMaladies.size() == 0)
	{
		AfxMessageBox((CString)"No server ready or you havent get the disease list.");
		return;
	}
	if (counter == 0)
	{
		AfxMessageBox((CString)"No server can analyse this disease.");
		return;
	}
	for (int i=0;i<counter;i++) 
	{
		clientSocket.Create();
		clientSocket.Connect(CString((it->second).getAddr().c_str()), (it->second).getPort());
		int returncode = clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse, maladie));
		if (returncode != -1) {
			Analyse * a = parser.parseResultatCiblee(clientSocket.receiveMsg());
			for (auto res : a->getResults())
			{
				result.insert(res);
				if (res.second)
				{
					result[res.first] = true;
				}

			}

		}
		it++;
		
		clientSocket.Close();
	}
	afficherResultatAnalyse(result);

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

void InterfaceHM::afficherResultatAnalyse(map<string, bool> res)
{
	string s= "Result de l'analyse:\r\n\r\n";
	for (auto r : res)
	{
		if (r.second)
		{
			s += r.first;
			s += " possible\r\n";
		}
		else {
			s += r.first;
			s += " not possible\r\n";
		}
	}
	AfxMessageBox(CString(s.c_str()));
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






