
// Prova7872View.cpp: implementação da classe CProva7872View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "Prova7872.h"
#endif

#include "Prova7872Doc.h"
#include "Prova7872View.h"
#include "CConfDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProva7872View

IMPLEMENT_DYNCREATE(CProva7872View, CView)

BEGIN_MESSAGE_MAP(CProva7872View, CView)
	// Comandos de impressão padrão
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_COR_SOL, &CProva7872View::OnCorSol)
	ON_COMMAND(ID_COR_TERRA, &CProva7872View::OnCorTerra)
	ON_COMMAND(ID_ORBITAS, &CProva7872View::OnOrbitas)
	ON_COMMAND(ID_TIMER, &CProva7872View::OnTimer)
	ON_COMMAND(ID_COR_LUA2, &CProva7872View::OnCorLua2)
	ON_COMMAND(ID_RAIO2, &CProva7872View::OnRaio2)
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_TIMER, &CProva7872View::OnUpdateTimer)
	ON_UPDATE_COMMAND_UI(ID_ORBITAS, &CProva7872View::OnUpdateOrbitas)
END_MESSAGE_MAP()

// Construção/destruição de CProva7872View

CProva7872View::CProva7872View() noexcept
{
	// TODO: adicione o código de construção aqui

}

CProva7872View::~CProva7872View()
{
}

BOOL CProva7872View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modifique a classe ou os estilos de Janela aqui modificando
	//  os cs CREATESTRUCT

	return CView::PreCreateWindow(cs);
}

// desenho de CProva7872View

void CProva7872View::OnDraw(CDC* pDC)
{
	CPoint pTerra{};
	CPoint pLua{};

	pTerra.x = GetDocument()->pSol.x - GetDocument()->oTerra * cos((float)GetDocument()->angTerra * 3.141592 / 180);
	pTerra.y = GetDocument()->pSol.y - GetDocument()->oTerra * sin((float)GetDocument()->angTerra * 3.141592 / 180);

	CPen* OldPen, Orbit(PS_DOT, 1, GetDocument()->cCaneta);
	OldPen = pDC->SelectObject(&Orbit);
	pDC->SelectObject(Orbit);

	pDC->Ellipse((GetDocument()->pSol.x - GetDocument()->oTerra), (GetDocument()->pSol.y - GetDocument()->oTerra), (GetDocument()->pSol.x + GetDocument()->oTerra), (GetDocument()->pSol.y + GetDocument()->oTerra));
	pDC->Ellipse((pTerra.x - GetDocument()->oLua), (pTerra.y - GetDocument()->oLua), (pTerra.x + GetDocument()->oLua), (pTerra.y + GetDocument()->oLua));


	pDC->SelectObject(OldPen);


	pLua.x = pTerra.x - GetDocument()->oLua * cos((float)GetDocument()->angLua * 3.141592 / 180);
	pLua.y = pTerra.y - GetDocument()->oLua * sin((float)GetDocument()->angLua * 3.141592 / 180);



	CBrush* OldBrush, Sun(GetDocument()->cSol), Earth(GetDocument()->cTerra), Moon(GetDocument()->cLua);
	OldBrush = pDC->SelectObject(&Sun);
	pDC->SelectObject(Sun);
	pDC->Ellipse((GetDocument()->pSol.x - GetDocument()->rSol), (GetDocument()->pSol.y - GetDocument()->rSol), (GetDocument()->pSol.x + GetDocument()->rSol), (GetDocument()->pSol.y + GetDocument()->rSol));

	pDC->SelectObject(Earth);
	pDC->Ellipse((pTerra.x - GetDocument()->rTerra), (pTerra.y - GetDocument()->rTerra), (pTerra.x + GetDocument()->rTerra), (pTerra.y + GetDocument()->rTerra));

	pDC->SelectObject(Moon);
	pDC->Ellipse((pLua.x - GetDocument()->rLua), (pLua.y - GetDocument()->rLua), (pLua.x + GetDocument()->rLua), (pLua.y + GetDocument()->rLua));
	// TODO: adicione o código de desenho para dados nativos aqui
}


// impressão de CProva7872View

BOOL CProva7872View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// preparação padrão
	return DoPreparePrinting(pInfo);
}

void CProva7872View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione inicialização extra antes de imprimir
}

void CProva7872View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione a limpeza após a impressão
}


// Diagnóstico de CProva7872View

#ifdef _DEBUG
void CProva7872View::AssertValid() const
{
	CView::AssertValid();
}

void CProva7872View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProva7872Doc* CProva7872View::GetDocument() const // a versão sem depuração está embutida
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProva7872Doc)));
	return (CProva7872Doc*)m_pDocument;
}
#endif //_DEBUG


// Manipuladores de mensagens de CProva7872View


void CProva7872View::OnCorSol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cSol = dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva7872View::OnCorTerra()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cTerra = dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva7872View::OnOrbitas()
{
	if (GetDocument()->cCaneta == RGB(0, 0, 0)) {
		GetDocument()->cCaneta = RGB(255, 255, 255);
	}
	else {
		GetDocument()->cCaneta = RGB(0, 0, 0);
	}
	Invalidate();
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva7872View::OnTimer()
{
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão
	if (GetDocument()->tempo) {
		KillTimer(GetDocument()->tempo);
		GetDocument()->tempo = 0;
	}
	else {
		GetDocument()->tempo = SetTimer(1, 365, NULL);
	}
}


void CProva7872View::OnCorLua2()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cLua= dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva7872View::OnRaio2()
{
	CConfDlg dlg;
	dlg.raioS = GetDocument()->rSol;
	dlg.raioTerra = GetDocument()->rTerra;
	dlg.raioLua = GetDocument()->rLua;
	dlg.orT = GetDocument()->oTerra;
	dlg.orL = GetDocument()->oLua;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->rSol = dlg.raioS;
		GetDocument()->rLua = dlg.raioLua;
		GetDocument()->rTerra = dlg.raioTerra;
		GetDocument()->oTerra = dlg.orT;
		GetDocument()->oLua = dlg.orL;
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva7872View::OnRButtonDown(UINT nFlags, CPoint point)
{
	GetDocument()->pSol = point;
	GetDocument()->SetModifiedFlag();
	GetDocument()->UpdateAllViews(NULL);

	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão

	CView::OnRButtonDown(nFlags, point);
}


void CProva7872View::OnDestroy()
{
	CView::OnDestroy();
	if (GetDocument()->tempo) {
		KillTimer(GetDocument()->tempo);
		GetDocument()->tempo = 0;
	}

	// TODO: Adicione seu código de manipulador de mensagens aqui
}


void CProva7872View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão
	if (nIDEvent == 1) {
		GetDocument()->angTerra += 1;
		GetDocument()->angTerra %= 720;
		GetDocument()->angLua+= 30;
		GetDocument()->angTerra %= 720;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CProva7872View::OnUpdateTimer(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->tempo);
	// TODO: Adicione seu código de manipulador da interface do usuário de atualização de comando aqui
}


void CProva7872View::OnUpdateOrbitas(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->cCaneta == RGB(0, 0, 0));
	// TODO: Adicione seu código de manipulador da interface do usuário de atualização de comando aqui
}
