
// MFCCalculatorDlg.h : header file
//

#pragma once
#include <vector>

#include "Matrix.h"


// CMFCCalculatorDlg dialog
class CMFCCalculatorDlg : public CDialogEx
{
// Construction
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
public:
	afx_msg void OnBnClickedButton1();

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonC();
private:
	Matrix firstMatrix;
	Matrix secondMatrix;
	CString outputText;
	int countOfRows;
	int countOfColumns;
public:
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonCountOfRows();
	afx_msg void OnBnClickedButtonCountOfColumns();
	afx_msg void OnBnClickedButtonMakeFirstMatrix();
	afx_msg void OnBnClickedButtonMatrixMultiplication();
	afx_msg void OnBnClickedButtonMakeSecondMatrix();
	afx_msg void OnBnClickedButtonNextItem();
	afx_msg void OnEnChangeEditResult();
};
