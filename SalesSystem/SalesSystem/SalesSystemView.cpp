
// SalesSystemView.cpp : CSalesSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SalesSystem.h"
#endif

#include "SalesSystemDoc.h"
#include "SalesSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalesSystemView

IMPLEMENT_DYNCREATE(CSalesSystemView, CView)

BEGIN_MESSAGE_MAP(CSalesSystemView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSalesSystemView ����/����

CSalesSystemView::CSalesSystemView()
{
	// TODO: �ڴ˴���ӹ������

}

CSalesSystemView::~CSalesSystemView()
{
}

BOOL CSalesSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSalesSystemView ����

void CSalesSystemView::OnDraw(CDC* /*pDC*/)
{
	CSalesSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSalesSystemView ��ӡ

BOOL CSalesSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSalesSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSalesSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSalesSystemView ���

#ifdef _DEBUG
void CSalesSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CSalesSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSalesSystemDoc* CSalesSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSalesSystemDoc)));
	return (CSalesSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CSalesSystemView ��Ϣ�������
