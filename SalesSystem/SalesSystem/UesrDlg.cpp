// UesrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalesSystem.h"
#include "UesrDlg.h"
#include "InfoFile.h"

// CUesrDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(IDD_DIALOG_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_cfmPwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_cfmPwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUesrDlg ���

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUesrDlg ��Ϣ�������


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	// ��ʼ��
	m_user = TEXT("����Ա");

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	m_name = name;

	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton1()
{
	// �޸����빦��

	UpdateData(TRUE);

	if (m_newPwd.IsEmpty() || m_cfmPwd.IsEmpty()) {
		MessageBox(TEXT("�����벻��Ϊ��"));
		return;
	}

	if (m_newPwd != m_cfmPwd) {
		MessageBox(TEXT("��������ȷ�����벻һ��"));
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	if (m_newPwd == pwd) {
		MessageBox(TEXT("������������벻��һ��"));
		return;
	}

	// CString ת char*
	CStringA tmpName, tmpPwd;
	tmpName = name;
	tmpPwd = m_newPwd;

	file.WritePwd(tmpName.GetBuffer(),tmpPwd.GetBuffer());

	MessageBox(TEXT("�޸ĳɹ�"));

	m_newPwd.Empty();
	m_cfmPwd.Empty();

	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton2()
{
	// ȡ����ť
	m_newPwd.Empty();
	m_cfmPwd.Empty();

	UpdateData(FALSE);
}
