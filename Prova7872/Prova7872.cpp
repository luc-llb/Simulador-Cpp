
// Prova7872.cpp: define os comportamentos de classe para o aplicativo.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Prova7872.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "Prova7872Doc.h"
#include "Prova7872View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProva7872App

BEGIN_MESSAGE_MAP(CProva7872App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CProva7872App::OnAppAbout)
	// Comandos do documento baseados no arquivo padrão
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Comando de configuração de impressão padrão
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// construção de CProva7872App

CProva7872App::CProva7872App() noexcept
{

	// suporte ao Gerenciador de Reinicialização
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Se o aplicativo for compilado usando o suporte a Common Language Runtime (/clr):
	//     1) Essa configuração adicional é necessária para o suporte ao Gerenciador de Reinicialização funcionar corretamente.
	//     2) no seu projeto, você deve adicionar uma referência a System.Windows.Forms para compilar.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: substitua a cadeia de caracteres de ID do aplicativo abaixo pela cadeia de caracteres de ID exclusiva. Recomendado
	// o formato de cadeia de caracteres é CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Prova7872.AppID.NoVersion"));

	// TODO: adicione código de construção aqui,
	// Coloque todas as inicializações significativas em InitInstance
}

// O único objeto de CProva7872App

CProva7872App theApp;


// inicialização de CProva7872App

BOOL CProva7872App::InitInstance()
{
	// InitCommonControlsEx() será necessário no Windows XP se um aplicativo
	// o manifesto especifica o uso do Comctl32.dll versão 6 ou posterior para habilitar
	// estilos visuais. Caso contrário, a criação de qualquer janela falhará.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Definir esta opção para incluir todas as classes de controle comuns que você deseja usar
	// em seu aplicativo.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Inicializar bibliotecas OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// O AfxInitRichEdit2() é necessário para usar o controle RichEdit
	// AfxInitRichEdit2();

	// Inicialização padrão
	// Se você não estiver usando esses recursos e desejar reduzir o tamanho
	// do seu arquivo executável final, que você deve remover de
	// as rotinas de inicialização específicas que não são necessárias
	// Alterar a chave do Registro sob a qual as configurações são armazenadas
	// TODO: você deve modificar esta cadeia de caracteres para algo apropriado
	// como o nome da sua empresa ou organização
	SetRegistryKey(_T("Aplicativos Locais Gerados pelo AppWizard"));
	LoadStdProfileSettings(4);  // Carregar opções de arquivo INI padrão (incluindo MRU)


	// Registre os modelos de documento do aplicativo. Modelos de documento
	//  serve como a conexão entre os documentos, janelas de quadro e modos de exibição
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_Prova7872TYPE,
		RUNTIME_CLASS(CProva7872Doc),
		RUNTIME_CLASS(CChildFrame), // quadro filho MDI personalizado
		RUNTIME_CLASS(CProva7872View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// criar uma janela de Quadro MDI principal
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Analisar a linha de comando para comandos shell padrão, DDE, arquivo aberto
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Comandos de expedição especificados na linha de comando. Retornarão FALSE se
	// aplicativo foi inicializado com /RegServer, /Register, /Unregserver ou /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// A janela principal foi inicializada, portanto, mostre-a e atualize-a
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CProva7872App::ExitInstance()
{
	//TODO: manipule recursos adicionais que podem ter sido adicionados
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// Manipuladores de mensagens de CProva7872App


// Caixa de diálogo CAboutDlg usada para o Sobre o Aplicativo

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

// Implementação
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// Comando de aplicativo para executar a caixa de diálogo
void CProva7872App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Manipuladores de mensagens de CProva7872App





void CAboutDlg::OnBnClickedOk()
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	CDialogEx::OnOK();
}
