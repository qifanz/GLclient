
// AnalyseGenomeClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAnalyseGenomeClientApp:
// See AnalyseGenomeClient.cpp for the implementation of this class
//

class CAnalyseGenomeClientApp : public CWinApp
{
public:
	CAnalyseGenomeClientApp();

// Overrides
public:
	virtual BOOL InitInstance();

	
// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAnalyseGenomeClientApp theApp;