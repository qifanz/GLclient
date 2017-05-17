#include "stdafx.h"
#include <string>
#include <map>
#include <list>
#include "InterfaceHM.h"

using namespace std;


InterfaceHM::InterfaceHM()
{

}
InterfaceHM::~InterfaceHM()
{
}
void InterfaceHM::consulterResultatAnalyse(Analyse analyse) {
	analyse.afficher();
}
list<Analyse> InterfaceHM::consulterListAnalyse() {
	/*list<Analyse>::iterator listanalyse;
	lit(listanalyse.begin()),
	lend(listanalyse.end());
	for (; lit != lend; ++lit) {
	lit.afficher();
	}*/

}
/*
InterfaceHM::consulterListAnalyse(list<Analyse> ) {
	list<Analyse>::const_iterator iterator;
	lit(listanalyse.begin()),
	lend(listanalyse.end());
	for (; lit != lend; ++lit) {
	lit.afficher();
	}
}
*/
void InterfaceHM::demanderAnalyseGenerale(Analyse analyse) {
	interfaceClient.prepareMsgAnalyse(analyse);
}

void InterfaceHM ::demanderAnalyseCiblee(Analyse analyse, string maladie){
	interfaceClient.prepareMsgAnalyse(analyse,maladie);
}

map<list<string>, string>  listerMaladies() {
	/*map<list<string>, string>::iterator lM;
	for (lM = map.begin(); p != map.end(); lM++)
	{
		list<string> l = lM->first;
		list<string>::const_iterator
		lit(l.begin()),
		lend(l.end());
		for (; lit != lend; ++lit) {
			cout << *lit << endl;
		}
	cout << p->second < endl;
	}*/



}