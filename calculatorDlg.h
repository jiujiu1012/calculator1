
// calculatorDlg.h: 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void Calculator();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton16add();
	afx_msg void OnBnClickedButton8mul();
	afx_msg void OnBnClickedButton12sub();
	afx_msg void OnBnClickedButton4dev();
	afx_msg void OnBnClickedButton5num1();
	afx_msg void OnBnClickedButton7num2();
	afx_msg void OnBnClickedButton6num3();
	afx_msg void OnBnClickedButton9num4();
	afx_msg void OnBnClickedButton11num5();
	afx_msg void OnBnClickedButton10num6();
	afx_msg void OnBnClickedButton13num7();
	afx_msg void OnBnClickedButton15num8();
	afx_msg void OnBnClickedButton14num9();
	afx_msg void OnBnClickedButton19zero();
	afx_msg void OnBnClickedButton17left();
	afx_msg void OnBnClickedButton18right();
	afx_msg void OnBnClickedButton20equal();
	afx_msg void OnBnClickedButton1ac();
	afx_msg void OnBnClickedButton2bs();
	afx_msg void OnBnClickedButton3point();
	afx_msg void OnEnChangeEdit1display();

private:
	CString Str1;
	CString Str2;
	CString Str3;
	CString TempStr;

public:
	afx_msg void OnEnChangeEdit1history2();
	CButton x;
};
