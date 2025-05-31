#pragma once
#include "afxdialogex.h"


// caixa de diálogo de CConfDlg

class CConfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfDlg)

public:
	CConfDlg(CWnd* pParent = nullptr);   // construtor padrão
	virtual ~CConfDlg();

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Valor do raio do Sol
	double raioS;
	// Valor do raio da Terra
	double raioTerra;
	// valor do raio da Lua
	double raioLua;
	// Valor da orbita da Terra
	double orT;
	// Valor da orbita da Lua
	double orL;
//	afx_msg void OnEnChangeEdit3();
//	afx_msg void OnCorSol();
//	afx_msg void OnOrbitas();
//	afx_msg void OnTimer();
//	afx_msg void OnCorLua();
//	afx_msg void OnCorTerra();
};
