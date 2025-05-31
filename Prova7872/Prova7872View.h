
// Prova7872View.h: interface da classe CProva7872View
//

#pragma once


class CProva7872View : public CView
{
protected: // criar apenas com base na serialização
	CProva7872View() noexcept;
	DECLARE_DYNCREATE(CProva7872View)

// Atributos
public:
	CProva7872Doc* GetDocument() const;

// Operações
public:

// Substitui
public:
	virtual void OnDraw(CDC* pDC);  // substituído para desenhar esta visualização
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementação
public:
	virtual ~CProva7872View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRaio();
	afx_msg void OnCorLua();
	afx_msg void OnCorSol();
	afx_msg void OnCorTerra();
	afx_msg void OnOrbitas();
	afx_msg void OnTimer();
	afx_msg void OnCorLua2();
	afx_msg void OnRaio2();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUpdateTimer(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOrbitas(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // versão de depuração em Prova7872View.cpp
inline CProva7872Doc* CProva7872View::GetDocument() const
   { return reinterpret_cast<CProva7872Doc*>(m_pDocument); }
#endif

