

#include <string>
#include "Analyse.h"
#include <map>
#include <list>
#include "UtilParser.h"
#include "ClientSocket.h"
#include "Server.h"
using namespace std;

class InterfaceHM
{
	


public:
	InterfaceHM();
	~InterfaceHM();
	//void startConnection();
	//void disconnect();
	void demanderAnalyseGenerale(Analyse analyse);
	void demanderAnalyseCiblee(Analyse analyse, string maladie);
	void demanderListerMaladies();
	void afficherResultatListeMaladies();

	void initialise();
protected:
	void logger(char* msg);

protected:
	UtilParser parser;
	int id;
	string motDePasse;
	list<Server> serveurs;
	multimap<string , Server > listeMaladies;
	string version;
	ClientSocket clientSocket;

};
