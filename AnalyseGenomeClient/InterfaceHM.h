<<<<<<< HEAD
=======

>>>>>>> origin/master
#include <string>
#include "Analyse.h"
#include <map>
#include <list>
<<<<<<< HEAD
#include "UtilParser.h"
=======
>>>>>>> origin/master
using namespace std;

class InterfaceHM
{
public:
	InterfaceHM();
	~InterfaceHM();
public:
<<<<<<< HEAD
	ClientSocket clientSocket;
=======
>>>>>>> origin/master

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

<<<<<<< HEAD
	

};
=======
	InterfaceClient interfaceClient;

}

>>>>>>> origin/master
