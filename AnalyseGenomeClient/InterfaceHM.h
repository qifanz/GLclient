

#include <string>
#include "Analyse.h"
#include <map>
#include <list>
#include "UtilParser.h"
#include "ClientSocket.h"
using namespace std;

class InterfaceHM
{
	
public:
	InterfaceHM();
	~InterfaceHM();
	void startConnection();
	void disconnect();
	void receive();
	void demanderAnalyseGenerale(Analyse analyse);
	void demanderAnalyseCiblee(Analyse analyse, string maladie);
	void listerMaladies();



private:

	void initialise();

protected:
	UtilParser parser;
	int id;
	string motDePasse;
	list<string> serveurs;
	string version;
	ClientSocket clientSocket;

};
