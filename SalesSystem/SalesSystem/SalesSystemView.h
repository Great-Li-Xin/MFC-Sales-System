
// SalesSystemView.h : CSalesSystemView ��Ľӿ�
//

#pragma once


class CSalesSystemView : public CView
{
protected: // �������л�����
	CSalesSystemView();
	DECLARE_DYNCREATE(CSalesSystemView)

// ����
public:
	CSalesSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSalesSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SalesSystemView.cpp �еĵ��԰汾
inline CSalesSystemDoc* CSalesSystemView::GetDocument() const
   { return reinterpret_cast<CSalesSystemDoc*>(m_pDocument); }
#endif

