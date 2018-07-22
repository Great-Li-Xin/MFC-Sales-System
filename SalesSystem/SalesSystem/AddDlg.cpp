// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalesSystem.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(IDD_DIALOG_ADD)
	, m_price(0)
	, m_num(0)
	, m_newName(_T(""))
	, m_newPrice(0)
	, m_newNum(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT7, m_newName);
	DDX_Text(pDX, IDC_EDIT5, m_newPrice);
	DDX_Text(pDX, IDC_EDIT6, m_newNum);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	// ��ʼ��������
	CInfoFile file;
	// ����Ʒ����file������
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}

	m_combo.SetCurSel(0);
	// ���µ�һ����Ʒ�������
	 OnCbnSelchangeCombo1();
}


void CAddDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// �л���Ʒ�������¼�

	// ��ȡ��Ʒ����
	int index = m_combo.GetCurSel();

	CString name;
	m_combo.GetLBText(index, name);

	// ������Ʒ�����ƻ�ȡ�۸�Ϳ�� ������ʾ���ؼ���

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == name)
		{
			m_price = it->price;
			UpdateData(FALSE);
		}
	}
}


void CAddDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	// �����Ʒ�Ĺ���ʵ��
	if (m_num <= 0) {
		MessageBox(TEXT("�������Ҫ����0"));
		return;
	}

	// ����
	// ��ȡ����Ҫ��ӵ���Ʒ����
	int index = m_combo.GetCurSel();

	CString name;
	m_combo.GetLBText(index, name);

	// ������Ʒ�����ƻ�ȡ�۸�Ϳ�� ������ʾ���ؼ���

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == name)
		{
			// ��ӿ��
			it->num += m_num;
			m_num = 0;

			UpdateData(FALSE);
			MessageBox(TEXT("��ӳɹ�"));
		}
	}

	file.WriteDocline();
}


void CAddDlg::OnBnClickedButton4()
{
	// �������
	m_num = 0;
	UpdateData(FALSE);
	m_combo.SetCurSel(0);
	// ���µ�һ����Ʒ�������
	OnCbnSelchangeCombo1();
}
