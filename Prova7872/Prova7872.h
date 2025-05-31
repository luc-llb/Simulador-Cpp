
// Prova7872.h: arquivo de cabeçalho principal para o aplicativo Prova7872
//
#pragma once

#ifndef __AFXWIN_H__
	#error "inclua 'pch.h' antes de incluir este arquivo para PCH"
#endif

#include "resource.h"       // símbolos principais


// CProva7872App:
// Consulte Prova7872.cpp para a implementação desta classe
//

class CProva7872App : public CWinApp
{
public:
	CProva7872App() noexcept;


// Substitui
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementação
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProva7872App theApp;
