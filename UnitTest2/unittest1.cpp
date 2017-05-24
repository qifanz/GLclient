#include "stdafx.h"
#include "../AnalyseGenomeClient/stdafx.h"
#include "CppUnitTest.h"
#include "../AnalyseGenomeClient/Genome.h"
#include "../AnalyseGenomeClient/Analyse.h"
#include "../AnalyseGenomeClient/UtilParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: Ici, votre code de test

			Genome G(CString("Genome1.txt"));
			multiset<string> res = G.mots;

			Assert::AreEqual(
				("MA v1.0"),
				(*res.begin()).c_str()

			);
		}
		TEST_METHOD(TestAnalyse)
		{
			// TODO: Ici, votre code de test

			Genome G(CString("Genome1.txt"));
			Analyse A(G, "General");
			A.resultats.insert(pair<string, bool >("H5N5", true));
			map<string, bool> test = A.resultats;
			Assert::AreEqual(
				true,
				test["H5N5"]

			);
		}
		TEST_METHOD(TestprepareMsgAnalyse_Analyse) {
			UtilParser parser;
			Genome g(CString("Genome1.txt"));
			Analyse a(g, "Generale");
			string version = parser.getVersion();
			const char * msg = parser.prepareMsgAnalyse(a);
			string resultat = version + "\r\nCHECK ALL\r\nAAAT;TTTC;CCCG;GGGG;AACC;TTGG;ATAT;GCGC;\r\n\r\n";
			const char * result = resultat.c_str();

			Assert::AreEqual(
				result,
				msg,
				1
			);

		};
		TEST_METHOD(TestprepareMsgAnalyse_AnalyseMaladie) {
			UtilParser parser;
			Genome g(CString("Genome1.txt"));
			Analyse a(g, "H5N1");
			string version = parser.getVersion();
			const char * msg = parser.prepareMsgAnalyse(a, a.getType());
			string resultat = version + "\r\nCHECK DISEASE\r\nH5N1\r\nAAAT;TTTC;CCCG;GGGG;AACC;TTGG;ATAT;GCGC;\r\n\r\n";
			const char * result = resultat.c_str();

			Assert::AreEqual(
				result,
				msg,
				1);

		}
		TEST_METHOD(TestprepareMsgListeMaladie) {
			UtilParser parser;
			string version = parser.getVersion();
			string resultat = version + "\r\nGET DISEASES\r\n\r\n";
			const char * result = resultat.c_str();
			const char * msg = parser.prepareMsgListeMaladies();

			Assert::AreEqual(				
				result,
				msg,
				1
			);
		}
		TEST_METHOD(TestparseListeMaladies) {
			UtilParser parser;
			string message = "MA v1.0\r\nDISEASES\r\nH5N1\r\nH5N2\r\nPeste\r\n\r\n";
			const char * msg = message.c_str();
			list<string> result;
			result.push_back("H5N1");
			result.push_back("H5N2");
			result.push_back("Peste");
			list<string> retour = parser.parseListeMaladies(msg);
			bool identique = true;

			list<string>::const_iterator
				lit(retour.begin()),
				lend(retour.end()),
				lit2(result.begin());
			for (; lit != lend; ++lit) {
				lit2++;
				Assert::AreEqual(
					*lit,
					*lit2,
					1);
			}
		}
	};

}

