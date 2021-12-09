
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "CAcroAXDocShim.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//��ʼ��EDIT
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"1");
	GetDlgItem(IDC_EDIT2)->SetWindowText(L"1");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool AllisNum(string str);
bool AllisNum(string str)
{
	for (int i = 0; i < str.size(); i++)
		{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
			{
			 return false;
			}
		}
	return true;
}


CAcroAXDocShim pdf;
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	::AfxMessageBox(theApp.filepath);
	
	BOOL bAdobeReaderCreated = pdf.Create(_T(""), WS_VISIBLE, CRect(0, 0, 1, 1), AfxGetMainWnd(), 1050);
	if (!bAdobeReaderCreated)
	{
		::AfxMessageBox(_T("����PDFʧ��"));
		return;
	}
	if (!pdf.LoadFile(theApp.filepath))
	{
		::AfxMessageBox(_T("��pdf�ļ�ʧ��."));
		return;
	}
	pdf.printAllFit(TRUE);
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	BOOL bAdobeReaderCreated = pdf.Create(_T(""), WS_VISIBLE, CRect(0, 0, 1, 1), AfxGetMainWnd(), 1050);
	if (!bAdobeReaderCreated)
	{
		::AfxMessageBox(_T("����PDFʧ��"));
		return;
	}
	if (!pdf.LoadFile(theApp.filepath))
	{
		::AfxMessageBox(_T("��pdf�ļ�ʧ��."));
		return;
	}

	//ָ����ӡPDF�ڼ�ҳ���ڼ�ҳ
	//��ȡ��������
	CString str,str2;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	//�ж��Ƿ�Ϊ����
	std::string STDStr1(CW2A(str.GetString()));
	std::string STDStr2(CW2A(str2.GetString()));
	//�ж�ҳ��
	if (AllisNum(STDStr1) && AllisNum(STDStr2)) {
		
		pdf.printPages(atol(STDStr1.c_str()), atol(STDStr2.c_str()));
	}
	else
	{
		MessageBox(L"��ȡҳ��ʧ��");
	}
	
}


