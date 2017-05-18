#include "stdafx.h"
#include "Genome.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;
Genome::Genome() {};
Genome::Genome(string nomFichierGenome)
{
	ifstream fichier(nomFichierGenome, ios::in);
	if (fichier)
	{
		getline(fichier, version);
		string mot;
		while (getline(fichier, mot)) {
			mots.insert(mot);
			TRACE(mot.c_str());
			
		}
		TRACE("Genome cr¨¦¨¦\r\n" );
		fichier.close();
	}
	else
	{
		TRACE("Impossible d'ouvrir le fichier!\r\n");
	}
}

Genome::Genome()
{
}


Genome::~Genome()
{
}

void Genome::afficher()
{
	cout << version << endl;
	multiset<string>::const_iterator
		msit(mots.begin()),
		msend(mots.end());
	for (; msit != msend; ++msit) {
		cout << *msit << endl;
	}
}