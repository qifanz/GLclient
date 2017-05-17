#include <string>
#include "Analyse.h"
#include <map>
#include <list>
#include "UtilParser.h"
using namespace std;

class InterfaceHM
{
public:
	InterfaceHM();
	~InterfaceHM();
public:
	ClientSocket clientSocket;

	list<Analyse> consulterListAnalyse();

	void consulterResultatAnalyse(Analyse analyse);

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

	

};