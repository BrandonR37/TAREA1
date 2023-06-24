
// EjemploDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CEjemploDlg
class CEjemploDlg : public CDialogEx
{
// Construcción
public:
	CEjemploDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EJEMPLO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCargar();
	short m_address;
	short m_data;
	int m_opa;
	int m_opb;
	afx_msg void OnBnClickedButtonSum();
	int m_result;
	afx_msg void OnBnClickedButtonRest();
	afx_msg void OnBnClickedButtonMult();
	afx_msg void OnBnClickedButtonDiv();
	int m_pasos;
	int m_retardo;
	afx_msg void OnBnClickedButtonIzq();
	short m_pcontrol;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	CString m_titulo;
	CString m_texto;
	//CString m_titulo;
	//CString m_texto;
	afx_msg void OnBnClickedButtonPredef();
	afx_msg void OnBnClickedButtonDin();
	afx_msg void OnBnClickedButtonBorrar();
	afx_msg void OnBnClickedButtonAuto();
	BOOL m_rele;
	afx_msg void OnBnClickedCheckRele();
	afx_msg void OnBnClickedButtonEjecutar();
	CString m_combo;
};
