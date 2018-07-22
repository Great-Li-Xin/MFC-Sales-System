// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalesSystem.h"
#include "InfoDlg.h"

#include "InfoFile.h"

// CInfoDlg

IMPLEMENT_DYNCREATE(CInfoDlg, CFormView)

CInfoDlg::CInfoDlg()
	: CFormView(IDD_DIALOG_INFO)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CInfoDlg, CFormView)
END_MESSAGE_MAP()


// CInfoDlg ���

#ifdef _DEBUG
void CInfoDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInfoDlg ��Ϣ�������


void CInfoDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	// ������չ���
	// LVS_EX_FULLROWSELECTѡ������ | LVS_EX_GRIDLINES ��ʾ����
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// ��ʼ����ʾ
	CString field[] = { TEXT("��ƷID") ,TEXT("��Ʒ����"),TEXT("��Ʒ�۸�") ,TEXT("�������") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); i++)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	CInfoFile file;
	file.ReadDocline();

	int row = 0;
	CString str;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		str.Format(TEXT("%d"), it->id);
		m_list.InsertItem(row, str);
		int colume = 1;
		m_list.SetItemText(row, colume++, (CString)it->name.c_str());
		str.Format(TEXT("%d"), it->price);
		m_list.SetItemText(row, colume++, str);
		str.Format(TEXT("%d"), it->num);
		m_list.SetItemText(row, colume++, str);

		row++;
	}
}
