
// EjemploDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Ejemplo.h"
#include "EjemploDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CEjemploDlg



CEjemploDlg::CEjemploDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_EJEMPLO_DIALOG, pParent)
	, m_address(0)
	, m_data(0)
	, m_opa(0)
	, m_opb(0)
	, m_result(0)
	, m_pasos(0)
	, m_retardo(0)
	, m_pcontrol(0)
	, m_titulo(_T(""))
	, m_texto(_T(""))
	//, m_titulo(_T(""))
	//, m_texto(_T(""))
	, m_rele(FALSE)
	, m_combo(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEjemploDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EDIT_DATA, m_data);
	DDX_Text(pDX, IDC_EDIT_OPA, m_opa);
	DDX_Text(pDX, IDC_EDIT_OPB, m_opb);
	DDX_Text(pDX, IDC_STATIC_RESULT, m_result);
	DDX_Text(pDX, IDC_EDIT_PASOS, m_pasos);
	DDX_Text(pDX, IDC_EDIT_RETARDO, m_retardo);
	DDX_Text(pDX, IDC_STATIC_PCONTROL, m_pcontrol);
	//DDX_Text(pDX, IDC_EDIT1, m_titulo);
	//DDX_Text(pDX, IDC_EDIT2, m_texto);
	DDX_Text(pDX, IDC_EDIT_TITULO, m_titulo);
	DDX_Text(pDX, IDC_EDIT_TEXTO, m_texto);
	DDX_Check(pDX, IDC_CHECK_RELE, m_rele);
	DDX_CBString(pDX, IDC_COMBO, m_combo);
}

BEGIN_MESSAGE_MAP(CEjemploDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CARGAR, &CEjemploDlg::OnBnClickedButtonCargar)
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CEjemploDlg::OnBnClickedButtonSum)
	ON_BN_CLICKED(IDC_BUTTON_REST, &CEjemploDlg::OnBnClickedButtonRest)
	ON_BN_CLICKED(IDC_BUTTON_MULT, &CEjemploDlg::OnBnClickedButtonMult)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CEjemploDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_IZQ, &CEjemploDlg::OnBnClickedButtonIzq)
	ON_BN_CLICKED(IDC_BUTTON3, &CEjemploDlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_BUTTON1, &CEjemploDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_PREDEF, &CEjemploDlg::OnBnClickedButtonPredef)
	ON_BN_CLICKED(IDC_BUTTON_DIN, &CEjemploDlg::OnBnClickedButtonDin)
	ON_BN_CLICKED(IDC_BUTTON_BORRAR, &CEjemploDlg::OnBnClickedButtonBorrar)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, &CEjemploDlg::OnBnClickedButtonAuto)
	ON_BN_CLICKED(IDC_CHECK_RELE, &CEjemploDlg::OnBnClickedCheckRele)
	ON_BN_CLICKED(IDC_BUTTON_EJECUTAR, &CEjemploDlg::OnBnClickedButtonEjecutar)
END_MESSAGE_MAP()


// Controladores de mensajes de CEjemploDlg

BOOL CEjemploDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CEjemploDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CEjemploDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CEjemploDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/* ----Prototypes of Inp and Outp--- */

short _stdcall Inp32(short PortAddress);
void _stdcall Out32(short PortAddress, short data);

/*--------------------------------*/

void CEjemploDlg::OnBnClickedButtonCargar()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	Out32(m_address, m_data);
	Sleep(500);
	m_pcontrol = Inp32(m_address);
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedButtonSum()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	m_result = m_opa + m_opb;
	UpdateData(false);
	
}


void CEjemploDlg::OnBnClickedButtonRest()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	m_result = m_opa - m_opb;
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedButtonMult()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	m_result = m_opa * m_opb;
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedButtonDiv()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	m_result = m_opa / m_opb;
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedButtonIzq()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	for (int i = 0; i <= m_pasos; i++) {
		Out32(m_address, 0x01);
		Sleep(m_retardo);
		Out32(m_address, 0x02);
		Sleep(m_retardo);
		Out32(m_address, 0x04);
		Sleep(m_retardo);
		Out32(m_address, 0x08);
		Sleep(m_retardo);
	}
}


void CEjemploDlg::OnBnClickedButton3()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	for (int i = 0; i <= m_pasos; i++) {
		Out32(m_address, 0x08);
		Sleep(m_retardo);
		Out32(m_address, 0x04);
		Sleep(m_retardo);
		Out32(m_address, 0x02);
		Sleep(m_retardo);
		Out32(m_address, 0x01);
		Sleep(m_retardo);
	}
}


void CEjemploDlg::OnBnClickedButton1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control


}


void CEjemploDlg::OnBnClickedButtonPredef()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	MessageBox(__T("Este es el texto"), __T("Este es el titulo"));

}


void CEjemploDlg::OnBnClickedButtonDin()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	MessageBox(m_texto, m_titulo);
}


void CEjemploDlg::OnBnClickedButtonBorrar()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	m_titulo = "";
	m_texto = "";
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedButtonAuto()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	m_titulo = "Este es el titulo por default";
	m_texto = "Este es el texto por default";
	UpdateData(false);
}


void CEjemploDlg::OnBnClickedCheckRele()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (m_rele) {
		Out32(m_address, 0x10);
	}
	else
	{
		Out32(m_address, 0x00);
	}
}


void CEjemploDlg::OnBnClickedButtonEjecutar()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(true);
	if (m_combo == "Block") {
		WinExec("notepad.exe", SW_SHOW);
	}
	else if (m_combo == "Comandos") {
		WinExec("cmd.exe", SW_SHOW);
	}
	else if (m_combo == "Calculadora") {
		WinExec("calc.exe", SW_SHOW);
	}
	else if (m_combo == "Paint") {
		WinExec("mspaint.exe", SW_SHOW);
	}
	else if (m_combo == "Explorador de archivos") {
		WinExec("explorer.exe", SW_SHOW);
	}
}
