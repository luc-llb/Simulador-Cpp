
// Prova7872Doc.h: interface da classe CProva7872Doc
//


#pragma once


class CProva7872Doc : public CDocument
{
protected: // criar apenas com base na serialização
	CProva7872Doc() noexcept;
	DECLARE_DYNCREATE(CProva7872Doc)

// Atributos
public:
	COLORREF cCaneta{ RGB(0,0,0) };
	COLORREF cLua{ RGB(150,150,150) };
	COLORREF cSol{ RGB(255,255,0) };
	COLORREF cTerra{ RGB(100,100,255) };
	UINT tempo{ 0 };
	int angLua{ 0 };
	double rSol{ 150 };
	int angTerra{ 0 };
	double rLua{ 25 };
	double rTerra{ 50 };
	double oLua{ 85 };
	double oTerra{ 400 };
	CPoint pSol{ 600,300 };
// Operações
public:

// Substitui
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementação
public:
	virtual ~CProva7872Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Função auxiliar que define o conteúdo de pesquisa para um Manipulador de Pesquisa
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
