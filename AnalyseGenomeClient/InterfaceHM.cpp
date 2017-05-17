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
	UtilParser parser;
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse));
}

void InterfaceHM::demanderAnalyseCiblee(Analyse analyse, string maladie) {
	UtilParser parser;
	clientSocket.sendMsg(parser.prepareMsgAnalyse(analyse, maladie));
}

map<list<string>, string>  listerMaladies() {
	parser.prepareMsgListeMaladies();


}