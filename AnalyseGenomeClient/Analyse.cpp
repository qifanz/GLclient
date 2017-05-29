#include "stdafx.h"
#include "Analyse.h"
#include <iostream>
using namespace std;

Analyse::Analyse() {
	version = "1.1";
}

Analyse::Analyse(Genome genome, string type) : genome(genome), type(type), version(genome.getVersion())
{
	TRACE("%s\r\n", version.c_str());
}


Analyse::~Analyse()
{
}


ostream & operator<<(ostream & flux, Analyse const & analyse)
{
	analyse.afficher(flux);
	return flux;
}

void Analyse::afficher(ostream &flux) const
{
	flux << version << endl << type << endl;
	for (map<string, bool>::const_iterator it = resultats.begin(); it != resultats.end(); ++it)
	{
		flux << it->first << " : ";
		if (it->second) {
			flux << "oui" << endl;
		}
		else {
			flux << "non" << endl;
		}
	}
}


string Analyse::getVersion()
{
	return version;
}

string Analyse::getType()
{
	return type;
}

map<string, bool> Analyse::getResultats()
{
	return resultats;
}

void Analyse::addResult(pair<string, bool> res)
{
	
		resultats.insert(res);

}

Genome Analyse::getGenome()
{
	return genome;
}
