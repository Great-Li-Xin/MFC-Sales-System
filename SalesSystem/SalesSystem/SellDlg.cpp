// SellDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalesSystem.h"
#include "SellDlg.h"
#include "InfoFile.h"

// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(IDD_DIALOG_SELL)
	, m_price(0)
	, m_storage(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_storage);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSellDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSellDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSellDlg ���

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg ��Ϣ�������


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	// ��ʼ����Ϣ��������

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


void CSellDlg::OnCbnSelchangeCombo1()
{
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
			m_storage = it->num;
			UpdateData(FALSE);
		}
	}
}


void CSellDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	// ����Ĺ���ʵ��
	if (m_num <= 0) {
		MessageBox(TEXT("��������Ҫ����0"));
		return;
	}

	if (m_num > m_storage) {
		MessageBox(TEXT("�����������ܴ��ڿ����"));
		return;
	}

	// ����
	// ��ȡ����Ҫ�������Ʒ����
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
			it->num -= m_num;
			m_storage = it->num;

			// �����û����幺����Ϣ
			CString str;
			str.Format(_T("��Ʒ��%s \r\n���ۣ�%d \r\n������%d \r\n�ܼۣ�%d"), name, m_price, m_num, m_price*m_num);
			m_sellInfo = str;
			UpdateData(FALSE);
			MessageBox(TEXT("����ɹ�"));
		}
	}

	m_num = 0;
	m_sellInfo.Empty();
	UpdateData(FALSE);
	file.WriteDocline();
}


void CSellDlg::OnBnClickedButton2()
{
	// �������
	m_num = 0;
	m_sellInfo.Empty();
	UpdateData(FALSE);
	m_combo.SetCurSel(0);
	// ���µ�һ����Ʒ�������
	OnCbnSelchangeCombo1();
}
