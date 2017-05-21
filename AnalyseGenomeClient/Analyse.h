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
	void addResult(string maladie, bool resultat);
	void afficher();
	Genome getGenome();
	map<string, bool> getResults();
	string getType();
	string getVersion();

private:
	string type;
	string version;
	map<string, bool> resultats;
	Genome genome;
};


