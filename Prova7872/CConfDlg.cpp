// CConfDlg.cpp : arquivo de implementação
//

#include "pch.h"
#include "Prova7872.h"
#include "afxdialogex.h"
#include "CConfDlg.h"


// caixa de diálogo de CConfDlg

IMPLEMENT_DYNAMIC(CConfDlg, CDialogEx)

CConfDlg::CConfDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, raioS(0)
	, raioTerra(0)
	, raioLua(0)
	, orT(0)
	, orL(0)
{

}

CConfDlg::~CConfDlg()
{
}

void CConfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, raioS);
	DDX_Text(pDX, IDC_EDIT2, raioTerra);
	DDX_Text(pDX, IDC_EDIT4, raioLua);
	DDX_Text(pDX, IDC_EDIT3, orT);
	DDX_Text(pDX, IDC_EDIT5, orL);
}


BEGIN_MESSAGE_MAP(CConfDlg, CDialogEx)
//	ON_EN_CHANGE(IDC_EDIT3, &CConfDlg::OnEnChangeEdit3)
//	ON_COMMAND(ID_COR_SOL, &CConfDlg::OnCorSol)
//	ON_COMMAND(ID_ORBITAS, &CConfDlg::OnOrbitas)
//	ON_COMMAND(ID_TIMER, &CConfDlg::OnTimer)
//	ON_COMMAND(ID_COR_LUA, &CConfDlg::OnCorLua)
//	ON_COMMAND(ID_COR_TERRA, &CConfDlg::OnCorTerra)
END_MESSAGE_MAP()


// manipuladores de mensagens de CConfDlg


//void CConfDlg::OnEnChangeEdit3()
//{
	// TODO:  Se este for um controle RICHEDIT, o controle não
	// enviará esta notificação a menos que você substitua a função CDialogEx::OnInitDialog()
	// e chame CRichEditCtrl().SetEventMask()
	// com ENM_CHANGE flag ORed na máscara.

	// TODO:  Adicione seu código de manipulador de notificações de controle aqui
//}


//void CConfDlg::OnCorSol()
//{
	// TODO: Adicione seu código de manipulador de comandos aqui
//}


//void CConfDlg::OnOrbitas()
//{
	// TODO: Adicione seu código de manipulador de comandos aqui
//}


//void CConfDlg::OnTimer()
//{
	// TODO: Adicione seu código de manipulador de comandos aqui
//}


//void CConfDlg::OnCorLua()
//{
	// TODO: Adicione seu código de manipulador de comandos aqui
//}


//void CConfDlg::OnCorTerra()
//{
	// TODO: Adicione seu código de manipulador de comandos aqui
//}
