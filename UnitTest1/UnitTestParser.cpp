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

		TEST_METHOD(paserMsgAnalyseGenerale)
		{
			UtilParser parser;
			Genome g;
			g.addMot("AAAT");
			g.addMot("TTTC");
			Analyse a(g, "Generale");
			const char * msg = parser.prepareMsgAnalyse(a);
			string resultat = "MA v1.0\r\nCHECK ALL\r\nAAAT;TTTC;\r\n\r\n";
			const char * result = resultat.c_str();

			Assert::AreEqual(
				result,
				msg,
				1);
		
		}
		TEST_METHOD(paserMsgAnalyseCiblee)
		{
			UtilParser parser;
			Genome g;
			g.addMot("AAAT");
			g.addMot("TTTC");
			Analyse a(g, "aaa");
			const char * msg = parser.prepareMsgAnalyse(a,"aaa");
			string resultat = "MA v1.0\r\nCHECK DISEASE\r\naaa\r\nAAAT;TTTC;\r\n\r\n";
			const char * result = resultat.c_str();

			Assert::AreEqual(
				result,
				msg,
				1);

		}
		TEST_METHOD(paserMsglisterMaladies)
		{

			UtilParser parser;
			string version = parser.getVersion();
			string resultat = version + "\r\nGET DISEASES\r\n\r\n";
			const char * result = resultat.c_str();
			const char * msg = parser.prepareMsgListeMaladies();

			Assert::AreEqual(
				msg,
				resultat.c_str(),
				1
			);
		}
		TEST_METHOD(paseResultlisterMaladies)
		{


			UtilParser parser;
			string message = "MA v1.0\r\nDISEASES\r\nH5N1\r\nH5N2\r\nPeste\r\n\r\n";
			char msg[2048];
			strcpy_s(msg, message.c_str());
			list<string> result;
			result.push_back("H5N1");
			result.push_back("H5N2");
			result.push_back("Peste");
			list<string> retour = parser.parseListeMaladies(msg);
			bool identique = true;
			Assert::AreEqual(
				(*retour.begin()).c_str(),
				(*result.begin()).c_str(),
				1
			);
			Assert::AreEqual(
				(*retour.begin()++).c_str(),
				(*result.begin()++).c_str(),
				1
			);
		}
		TEST_METHOD(paseResultAnalyseCiblee)
		{
			UtilParser parser;
			string message = "MA v1.0\r\nDISEASE H5N1\r\n1\r\n\r\n";
			char msg[2048];
			strcpy_s(msg, message.c_str());
			Analyse * a = parser.parseResultatCiblee(msg);
			
			Assert::IsTrue(
				a->getResultats()["H5N1"]
				);

			
		}

		TEST_METHOD(paseResultAnalyseGenerale)
		{
			UtilParser parser;
			string message = "MA v1.0\r\nDISEASE H5N1\r\nDISEASE H5N3\r\n\r\n";
			char msg[2048];
			strcpy_s(msg, message.c_str());
			Analyse * a = parser.parseResultatGeneral(msg);

			Assert::IsTrue(
				a->getResultats()["H5N1"]
			);
			Assert::IsTrue(
				a->getResultats()["H5N3"]
			);
		}
	};

}

