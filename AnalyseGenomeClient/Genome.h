#pragma once
#include <string>
#include <set>

using namespace std;
class Genome
{
public:
	Genome();
	Genome(string nomFichierGenome);
	~Genome();
	void afficher();
	string getVersion();
	multiset<string> getMots();
private:
	string version;
	multiset<string> mots;
};
