#pragma once
#include <string>
#include <map>
#include "Genome.h"
using namespace std;
class Analyse
{
public:
	Analyse();
	Analyse(Genome genome, string type);
	~Analyse();
	
	friend ostream& operator<<(ostream &flux, Analyse const& analyse);
	void afficher(ostream &flux) const;
	string getVersion();
	string getType();
	map<string, bool> getResultats();
	void addResult(pair<string, bool>res);
	Genome getGenome();

private :
	map<string, bool> resultats;
	Genome genome;
	string type;

private :
	string version;
};


