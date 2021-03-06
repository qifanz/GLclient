#include "stdafx.h"
#include <string>
#include <map>
#include <list>
#include <fstream>
#include "InterfaceClient.h"

using namespace std;


InterfaceClient::InterfaceClient()
{
	version = "1.0";
}
InterfaceClient::~InterfaceClient()
{
}
void InterfaceClient::demanderAnalyseGenerale(Analyse analyse) {
	map<string, bool> result;
	for (auto s : serveurs)
	{
		clientSocket.Create();
		clientSocket.Connect(CString(s.getAddr().c_str()), s.getPort());

		int returncode = clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
		if (returncode!=-1) {
			Analyse* a = parser.parseResultatGeneral(clientSocket.receiveMsg());
			for (auto res : a->getResultats())
			{
			
				result.insert(res);
			}
			//AfxMessageBox(CString(clientSocket.receiveMsg()));
		}
		
		clientSocket.Close();
	}
	afficherResultatAnalyse(result);
}

void InterfaceClient::demanderAnalyseCiblee(Analyse analyse, string maladie) {
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
			for (auto res : a->getResultats())
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


void InterfaceClient::demanderListerMaladies() {
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

void InterfaceClient::afficherResultatListeMaladies()
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

void InterfaceClient::afficherResultatAnalyse(map<string, bool> res)
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


void InterfaceClient::initialise()
{
	ifstream fichier("res/listeServeurs.txt", ios::in);
	if (fichier)
	{

			string line;
			string adresse;
			string port;
			while (getline(fichier, line)) {
				size_t pos = line.find(":");
				adresse = line.substr(0, pos);
				port = line.substr(pos+1);
				serveurs.push_back(Server(adresse, stoi(port)));
				TRACE("%s %s \r\n", adresse.c_str(), port.c_str());
			}
			fichier.close();
		}
	
	else
	{
		AfxMessageBox((CString)("Impossible d'ouvrir le fichier de liste des serveurs!\r\n"));
	}
}

void InterfaceClient::logger(char * msg)
{

	{
		ofstream fichier("res/log.txt", ios::out | ios::app); 

		if (fichier)
		{
			fichier << msg << endl;
			fichier.close();
		}
		else
			AfxMessageBox((CString)("Impossible d'ouvrir le fichier log.txt!\r\n"));

	}

}






