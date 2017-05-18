#pragma once
#include <string>
#include <set>

using namespace std;
class Genome
{
public:
	Genome();
	Genome(string nomFichierGenome);
	Genome();
	~Genome();
public:
	void afficher();
public:
	string version;
	multiset<string> mots;
};
