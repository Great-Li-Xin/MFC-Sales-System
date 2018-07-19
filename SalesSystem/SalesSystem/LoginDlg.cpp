// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalesSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedButton1()
{
	// ��¼��ť����¼�
	UpdateData(TRUE);

	if (m_user.IsEmpty() || m_pwd.IsEmpty()) {
		MessageBox(TEXT("�û������벻��Ϊ��"));
		return;
	}

	// ��ȡ��ȷ��ֵ
	CInfoFile file;
	CString name;
	CString pwd;
	file.ReadLogin(name, pwd);

	if (name == m_user) {
		if (pwd == m_pwd) {
			CDialog::OnCancel();
		}
		else
		{
			MessageBox(TEXT("�������"));
		}
	}
	else
	{
		MessageBox(TEXT("�û�������"));
	}
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	// Ĭ�ϵ�¼��Ϣ
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_user = name;
	m_pwd = pwd;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnBnClickedButton2()
{
	// �Ƴ���������
	exit(0);
}


void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CDialogEx::OnClose();
	exit(0);
}
