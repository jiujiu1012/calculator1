
// calculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

int count = 0;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcalculatorDlg 对话框



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON10num6, x);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON16ADD, &CcalculatorDlg::OnBnClickedButton16add)
	ON_BN_CLICKED(IDC_BUTTON8MUL, &CcalculatorDlg::OnBnClickedButton8mul)
	ON_BN_CLICKED(IDC_BUTTON12SUB, &CcalculatorDlg::OnBnClickedButton12sub)
	ON_BN_CLICKED(IDC_BUTTON4DEV, &CcalculatorDlg::OnBnClickedButton4dev)
	ON_BN_CLICKED(IDC_BUTTON5num1, &CcalculatorDlg::OnBnClickedButton5num1)
	ON_BN_CLICKED(IDC_BUTTON7num2, &CcalculatorDlg::OnBnClickedButton7num2)
	ON_BN_CLICKED(IDC_BUTTON6num3, &CcalculatorDlg::OnBnClickedButton6num3)
	ON_BN_CLICKED(IDC_BUTTON9num4, &CcalculatorDlg::OnBnClickedButton9num4)
	ON_BN_CLICKED(IDC_BUTTON11num5, &CcalculatorDlg::OnBnClickedButton11num5)
	ON_BN_CLICKED(IDC_BUTTON10num6, &CcalculatorDlg::OnBnClickedButton10num6)
	ON_BN_CLICKED(IDC_BUTTON13num7, &CcalculatorDlg::OnBnClickedButton13num7)
	ON_BN_CLICKED(IDC_BUTTON15num8, &CcalculatorDlg::OnBnClickedButton15num8)
	ON_BN_CLICKED(IDC_BUTTON14num9, &CcalculatorDlg::OnBnClickedButton14num9)
	ON_BN_CLICKED(IDC_BUTTON19zero, &CcalculatorDlg::OnBnClickedButton19zero)
	ON_BN_CLICKED(IDC_BUTTON17left, &CcalculatorDlg::OnBnClickedButton17left)
	ON_BN_CLICKED(IDC_BUTTON18right, &CcalculatorDlg::OnBnClickedButton18right)
	ON_BN_CLICKED(IDC_BUTTON20equal, &CcalculatorDlg::OnBnClickedButton20equal)
	ON_BN_CLICKED(IDC_BUTTON1AC, &CcalculatorDlg::OnBnClickedButton1ac)
	ON_BN_CLICKED(IDC_BUTTON2BS, &CcalculatorDlg::OnBnClickedButton2bs)
	ON_BN_CLICKED(IDC_BUTTON3POINT, &CcalculatorDlg::OnBnClickedButton3point)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//设置运算符的优先级
int Lv(char m)
{
	switch (m)
	{
	case '+':
		return 1; break;
	case '-':
		return 1; break;
	case '*':
		return 2; break;
	case '/':
		return 2; break;
	case '(':
		return 0; break;
	case ')':
		return 0; break;
	case '!':
		return -1; break;
	default:break;
	}
}
//声明堆栈类
template<class T>
class stack;
//节点类
template <class T>
class Node {
	friend stack<T>; //堆栈类为友元
private:
	T data;
	Node<T>* link;
};

template<class T>
class stack
{
public:
	stack() { top = 0; }
	bool IsEmpty() const
	{
		return top == 0;
	}
	//bool IsFull() const;
	T Top() const;
	stack<T>& Add(const T& x); //添加方法
	stack<T>& Delete(T& x);    //删除方法
private:
	Node<T>* top;
};

//返回栈顶元素
template<class T>
T stack<T>::Top()const
{
	return top->data;
}

//在栈顶添加元素，先将元素传给节点p的data，再将data传给top
template<class T>
stack<T>& stack<T>::Add(const T& x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}

//在栈顶删除元素，将要删除的data传给x，然后删除p
template<class T>
stack<T>& stack<T>::Delete(T& x)
{
	x = top->data;
	Node<T>* p = top;
	top = top->link;
	delete p;
	return *this;
}

//加号，下面是对计算器的各个按键的处理，先获取按键上的符号，再将其显示到显示框
void CcalculatorDlg::OnBnClickedButton16add()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "+"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "+" + "\n" ));

}



//乘号
void CcalculatorDlg::OnBnClickedButton8mul()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "*"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "*" + "\n"));
}


//减号
void CcalculatorDlg::OnBnClickedButton12sub()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "-"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "-" + "\n"));
}


//除号
void CcalculatorDlg::OnBnClickedButton4dev()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "/"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "/" + "\n"));
}



//数字1
void CcalculatorDlg::OnBnClickedButton5num1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "1"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "1" + "\n"));
}


//数字2
void CcalculatorDlg::OnBnClickedButton7num2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "2"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "2" + "\n"));
}

//数字3
void CcalculatorDlg::OnBnClickedButton6num3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "3"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "3" + "\n"));
}


//数字4
void CcalculatorDlg::OnBnClickedButton9num4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "4"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "4" + "\n"));
}

//数字5
void CcalculatorDlg::OnBnClickedButton11num5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "5"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "5" + "\n"));
}

//数字6
void CcalculatorDlg::OnBnClickedButton10num6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "6"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "6" + "\n"));
}

//数字7
void CcalculatorDlg::OnBnClickedButton13num7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "7"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "7" + "\n"));
}

//数字8
void CcalculatorDlg::OnBnClickedButton15num8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "8"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "8" + "\n"));
}


//数字9
void CcalculatorDlg::OnBnClickedButton14num9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "9"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "9" + "\n"));
}


//数字0
void CcalculatorDlg::OnBnClickedButton19zero() 
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "0"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "0" + "\n"));
}


//左括号
void CcalculatorDlg::OnBnClickedButton17left()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "("));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "(" + "\n"));
}


//右括号
void CcalculatorDlg::OnBnClickedButton18right()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + ")"));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + ")" + "\n"));
}


//等于号，按等于号的时候需要进行更复杂的操作，判断输入表达式是否规范，判断优先级，进行计算输出结果
void CcalculatorDlg::OnBnClickedButton20equal()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a, Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "="));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + " " + "="));
	stack<double> X;                  //堆栈1用作存操作数
	stack<char> Y;                    //堆栈2用作存运算符
	CString str = "";                 //str用作存放表达式
	CString str2 = "";                //str2用作拼接多位数字
	char c;                           //c用来存放Y中出栈的元素
	double C;                         //C用来存放X中出栈的元素
	GetDlgItemText(IDC_EDIT1display, str);   //获取面板上的表达式
	str += "!?";                      //在表达式的末尾加上！？方便后面的操作
	int i = 0;                        //i从0开始，用来检索表达式
	int e = 0;                          //e用来记录表达式中左括号的数量
	int f = 0;                          //f用来记录表达式中右括号的数量
	double t;                         //t用来保存两个double运算后的结果         
	double q;                         //q用来保存string转换成double后的数
	bool adc = true;
	//判断表达式是否规范
	for (int x = 0; str[x] != '!'; x++)
	{
		if (str[x] == '.')
		{
			if (str[x + 1] == '(' || str[x + 1] == ')' || str[x + 1] == '%' || str[x + 1] == '!' || str[x + 1] >= 42 && str[x + 1] <= 47)
			{
				//MessageBox("小数点后面没跟数字！");
				SetDlgItemText(IDC_EDIT1display, _T("小数点后面没跟数字！"));
				return;
			}
		}
		if (str[x] == '(')
		{
			e++;
			if (str[x + 1] == '.')
			{
				//MessageBox("小数点前面没跟数字！");
				SetDlgItemText(IDC_EDIT1display, _T("小数点前面没跟数字！"));
				return;
			}
			if (str[x + 1] == ')')
			{
				//	MessageBox("括号里面不能为空！");
				SetDlgItemText(IDC_EDIT1display, _T("括号里面不能为空！"));
				return;
			}
			if (x > 0 && str[x - 1] > 47 && str[x - 1] < 58)
			{
				//	MessageBox("括号前面没有运算符！");
				SetDlgItemText(IDC_EDIT1display, _T("括号前面没有运算符！"));
				return;
			}
		}

		if (str[x] == ')')
		{
			f++;
			if (str[x + 1] == '.')
			{
				//MessageBox("小数点前面没跟数字！");
				SetDlgItemText(IDC_EDIT1display, _T("小数点前面没跟数字！"));
				return;
			}
			if (str[x + 1] > 47 && str[x + 1] < 58)
			{
				//MessageBox("括号后面没有运算符！");
				SetDlgItemText(IDC_EDIT1display, _T("括号后面没有运算符！"));
				return;
			}
			int T = 0;
			while (T < x)
			{
				if (str[T] == '(')
					break;
				T++;
			}
			if (T == x)
			{
				//MessageBox("左右括号不匹配！");
				SetDlgItemText(IDC_EDIT1display, _T("左右括号不匹配！"));
				return;
			}
			if (str[x + 1] == '(')
			{
				//MessageBox("括号后面没有运算符！");
				SetDlgItemText(IDC_EDIT1display, _T("括号后面没有运算符！"));
				return;
			}
		}
		if (str[x] >= 42 && str[x] <= 47 || str[x] == '%')
		{
			if (str[x + 1] == '.')
			{
				//MessageBox("小数点前面没跟数字！");
				SetDlgItemText(IDC_EDIT1display, _T("小数点前面没跟数字！"));
				return;
			}
			if (x == 0 && str[x] != '-')
			{
				//MessageBox("运算符前面没有数字！");
				SetDlgItemText(IDC_EDIT1display, _T("运算符前面没有数字！"));
				return;
			}
			if (str[x + 1] == '!' || str[x + 1] == ')')
			{
				//MessageBox("运算符后面没有数字！");
				SetDlgItemText(IDC_EDIT1display, _T("运算符后面没有数字！"));
				return;
			}
			if (str[x + 1] >= 42 && str[x + 1] <= 47 || str[x + 1] == '%')
			{
				//MessageBox("连续的多个运算符！");
				SetDlgItemText(IDC_EDIT1display, _T("连续的多个运算符！"));
				return;
			}
		}
	}
	if (e != f)
	{
		//MessageBox("左右括号不匹配！");
		SetDlgItemText(IDC_EDIT1display, _T("左右括号不匹配！"));
		return;
}
	//开始对表达式进行入栈运算：
	while (str[i] != '?')
	{
		if (str[i] > 47 && str[i] < 58 || str[i] == '.')
		{
			int F = 0;             //F用来记录小数点的个数
			for (i; str[i] > 47 && str[i] < 58 || str[i] == '.'; i++)
			{
				str2 += str[i];
				if (str[i] == '.')
				{
					F++;
				}
				if (F > 1)
				{
					//MessageBox("一个数的小数点多于一个！");
					SetDlgItemText(IDC_EDIT1display, _T("一个数的小数点多于一个！"));
					return;
				}
			}
			q = atof(str2);  //用来存放string转换为double后的数
			str2 = "";
			X.Add(q);
		}
		if (str[i] >= 33 && str[i] <= 47)//33是感叹号，47是除号，所以范围比较大
		{
			if (i == 0 && str[i] == '-' && adc)
			{
				i++;
				if (str[i] > 47 && str[i] < 58 || str[i] == '.')
				{
					int F = 0;
					for (i; str[i] > 47 && str[i] < 58 || str[i] == '.'; i++)
					{
						str2 += str[i];
						if (str[i] == '.')
						{
							F++;
						}
						if (F > 1)
						{
							//	MessageBox("一个数的小数点多于一个！");
							SetDlgItemText(IDC_EDIT1display, _T("一个数的小数点多于一个！"));
							return;
						}
					}
					q = 0 - atof(str2);
					str2 = "";
					X.Add(q);
					i--;
				}
				else if (str[i] == '(')
				{
					adc = false;
					double Q = 0;
					X.Add(Q);
					i = -1;
				}
			}
			else if (Y.IsEmpty() || str[i] == '(' || Lv(str[i]) > Lv(Y.Top()))
			{
				Y.Add(str[i]);
				if (str[i + 1] == '-')
				{
					//cout << "..."<<i<<endl;
					i = i + 2;
					if (str[i] > 47 && str[i] < 58 || str[i] == '.')//************************
					{
						int F = 0;
						for (i; str[i] > 47 && str[i] < 58 || str[i] == '.'; i++)
						{
							str2 += str[i];
							if (str[i] == '.')
							{
								F++;
							}
							if (F > 1)
							{
								//	MessageBox("一个数的小数点多于一个！");
								SetDlgItemText(IDC_EDIT1display, _T("一个数的小数点多于一个！"));
								return;
							}
						}
						q = 0 - atof(str2);
						str2 = "";
						X.Add(q);
					}
					i--;
				}

			}
			else
			{
				if (str[i] == ')')
				{
					for (; Y.Top() != '('; Y.Delete(c))
					{
						char f = Y.Top();
						double a = X.Top();
						if (a == 0 && (f == '/' || f == '%'))
						{
							//MessageBox("除数不能为0！");
							SetDlgItemText(IDC_EDIT1display, _T("除数不能为0！"));
							return;
						}
						X.Delete(C);
						double b = X.Top();
						X.Delete(C);
						switch (f)
						{
						case '+':t = b + a; break;
						case '-':t = b - a; break;
						case '*':t = b * a; break;
						case '/':t = b / a; break;
						case '%':
							if (a<1 && a>-1)
							{
								//MessageBox("取整后除数为0！");
								SetDlgItemText(IDC_EDIT1display, _T("取整后除数为0！"));
								return;
							}
							t = (int)b % (int)a;
							break;
						default:break;
						}
						X.Add(t);

					}
					Y.Delete(c);
				}
				else
				{
					for (; !(Y.IsEmpty()) && Lv(str[i]) <= Lv(Y.Top()); Y.Delete(c))
					{
						char f = Y.Top();
						double a = X.Top();
						if (a == 0 && (f == '/' || f == '%'))
						{
							//MessageBox("除数不能为0！");
							SetDlgItemText(IDC_EDIT1display, _T("除数不能为0！"));
							return;
						}
						X.Delete(C);
						double b = X.Top();
						X.Delete(C);
						switch (f)
						{
						case '+':t = b + a; break;
						case '-':t = b - a; break;
						case '*':t = b * a; break;
						case '/':t = b / a; break;
						case '%':
							if (a<1 && a>-1)
							{
								//MessageBox("取整后除数为0！");
								SetDlgItemText(IDC_EDIT1display, _T("错误表达式"));
								return;
							}
							t = (int)b % (int)a;
							break;
						default:break;
						}
						X.Add(t);
						//cout << "..." << endl;
					}
					Y.Add(str[i]);
				}
			}
		}
		i++;
	}

	double I = X.Top();
	X.Delete(C);
	a.Format("%lf", I);
	SetDlgItemText(IDC_EDIT1display, _T(a));
	
	SetDlgItemText(IDC_EDIT1history, _T(Str + "=" + a));
}


//清屏
void CcalculatorDlg::OnBnClickedButton1ac()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1display, _T(""));
}

//退格
void CcalculatorDlg::OnBnClickedButton2bs()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp, num;
	GetDlgItemText(IDC_EDIT1display, num);
	temp = num.Left(num.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1display, temp);
}


void CcalculatorDlg::OnBnClickedButton3point()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a,Str;
	GetDlgItemText(IDC_EDIT1display, a);
	SetDlgItemText(IDC_EDIT1display, _T(a + "."));
	Str = a;
	SetDlgItemText(IDC_EDIT1history, _T(Str + "." + "\n"));
}



