// MyForm.cpp : implementation file
//

#include "stdafx.h"
#include "testSDI.h"
#include "MyForm.h"


// CMyForm

IMPLEMENT_DYNCREATE(CMyForm, CKofFormView)

CMyForm::CMyForm()
	: CKofFormView(CMyForm::IDD)
{

}

CMyForm::~CMyForm()
{
}

void CMyForm::DoDataExchange(CDataExchange* pDX)
{
	CKofFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyForm, CKofFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyForm::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMyForm diagnostics

#ifdef _DEBUG
void CMyForm::AssertValid() const
{
	CKofFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyForm::Dump(CDumpContext& dc) const
{
	CKofFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyForm message handlers

void CMyForm::OnBnClickedButton2()
{
	KOF_MSGBOXPARAMS a;
	a.lpszCaption = _T("����");
	a.lpszText = _T("�����ı������ı������ı������ı������ı������ı������ı������ı�����\r\n�ı������ı������ı������ı������ı������ı������ı������ı������ı�");
	a.lpszUserButtonText[0] = _T("����");
	a.uiUserButtonID[0] = 201;
	a.lpszUserButtonText[1] = _T("����");
	a.uiUserButtonID[1] = 202;
	a.dwStyle = MB_OK;
	a.dwStyle |= MB_ICONWARNING;
	a.bIgnoreStandardButtons = TRUE;
	a.bShowCheckBox = TRUE;
	a.lpszCheckBoxText = _T("fdf");
	a.bShowSeparator = TRUE;
	int aa = KofMessageBoxIndirect(&a);
	TRACE(_T("%d\r"), aa);
}
