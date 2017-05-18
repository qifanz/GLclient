

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
public:

	void startConnection();
		
	void demanderAnalyseGenerale(Analyse analyse);

	void demanderAnalyseCiblee(Analyse analyse, string maladie);


	map<list<string>, string>  listerMaladies();



private:

	void initialise();

protected:

	int id;

	string motDePasse;

	list<string> serveurs;

	string version;

	ClientSocket clientSocket;

};
