
// MFCCalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"
#include "StringToRPN.h"
#include "Operation.h"
#include "Matrix.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT_RESULT)
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorDlg dialog



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
	, outputText(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, outputText);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CMFCCalculatorDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CMFCCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CMFCCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CMFCCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_C, &CMFCCalculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CMFCCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_COUNT_OF_ROWS, &CMFCCalculatorDlg::OnBnClickedButtonCountOfRows)
	ON_BN_CLICKED(IDC_BUTTON_COUNT_OF_COLUMNS, &CMFCCalculatorDlg::OnBnClickedButtonCountOfColumns)
	ON_BN_CLICKED(IDC_BUTTON_MAKE_FIRST_MATRIX, &CMFCCalculatorDlg::OnBnClickedButtonMakeFirstMatrix)
	ON_BN_CLICKED(IDC_BUTTON_MATRIX_MULTIPLICATION, &CMFCCalculatorDlg::OnBnClickedButtonMatrixMultiplication)
	ON_BN_CLICKED(IDC_BUTTON_MAKE_SECOND_MATRIX, &CMFCCalculatorDlg::OnBnClickedButtonMakeSecondMatrix)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_ITEM, &CMFCCalculatorDlg::OnBnClickedButtonNextItem)
	ON_EN_CHANGE(IDC_EDIT_RESULT, &CMFCCalculatorDlg::OnEnChangeEditResult)
END_MESSAGE_MAP()


// CMFCCalculatorDlg message handlers

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Buttons

void CMFCCalculatorDlg::OnBnClickedButton0()
{
	outputText += "0";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton1()
{
	outputText += "1";
	UpdateData(FALSE);
	
}

void CMFCCalculatorDlg::OnBnClickedButton2()
{
	outputText += "2";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton3()
{
	outputText += "3";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton4()
{
	outputText += "4";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton5()
{
	outputText += "5";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton6()
{
	outputText += "6";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton7()
{
	outputText += "7";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton8()
{
	outputText += "8";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton9()
{
	outputText += "9";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButtonPlus()
{
	outputText += "+";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButtonMinus()
{
	outputText += "-";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButtonMultiply()
{
	outputText += "*";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButtonDivide()
{
	outputText += "/";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButtonEquals()
{
	if (outputText != "") 
	{
		StringToRPN tempRPN;
		//convertation CString to std::string consists in two steps:
		CT2CA pszConvertedAnsiString(outputText); // first step - Convert a TCHAR string to a LPCSTR
		std::string  historyTextStirng(pszConvertedAnsiString); // second step -  construct a std::string using the LPCSTR input
		Operation outcomeString(tempRPN.RPN(historyTextStirng));
		CString outcomeCString(outcomeString.getResult().c_str()); //we need to output this outcomeCString and that's it!!!
		outputText = outcomeCString;
	}
	UpdateData(FALSE);
	outputText = "";
}

void CMFCCalculatorDlg::OnBnClickedButtonC()
{
	outputText = "";
	UpdateData(FALSE);
}



void CMFCCalculatorDlg::OnBnClickedButtonCountOfRows()
{
	CT2CA pszConvertedAnsiString(outputText);
	std::string countOfRowsString (pszConvertedAnsiString);
	countOfRows = std::stoi(countOfRowsString);
	UpdateData(FALSE);
	outputText = "";
}


void CMFCCalculatorDlg::OnBnClickedButtonCountOfColumns()
{
	CT2CA pszConvertedAnsiString(outputText);
	std::string countOfColumnsString(pszConvertedAnsiString);
	countOfColumns = std::stoi (countOfColumnsString);
	UpdateData(FALSE);
	outputText = "";
}


void CMFCCalculatorDlg::OnBnClickedButtonMakeFirstMatrix()
{
	CT2CA pszConvertedAnsiString(outputText);
	std::string firstMatrixString = pszConvertedAnsiString;
	UpdateData(FALSE);
	firstMatrix = { firstMatrixString, countOfRows, countOfColumns };
	outputText = "";
}


void CMFCCalculatorDlg::OnBnClickedButtonMakeSecondMatrix()
{
	CT2CA pszConvertedAnsiString(outputText);
	std::string secondMatrixString = pszConvertedAnsiString;
	UpdateData(FALSE);
	secondMatrix = { secondMatrixString, countOfRows, countOfColumns };
	outputText = "";
}

void CMFCCalculatorDlg::OnBnClickedButtonMatrixMultiplication()
{
	Matrix resultMatrix;
	outputText = resultMatrix.multiplication(firstMatrix, secondMatrix).c_str();
	UpdateData(FALSE);
	outputText = "";
}



void CMFCCalculatorDlg::OnBnClickedButtonNextItem()
{
	outputText += ',';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnEnChangeEditResult()
{
	UpdateData(TRUE);
}
