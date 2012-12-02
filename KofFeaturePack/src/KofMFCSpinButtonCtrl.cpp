// ..\src\KofSpinButtonCtrl.cpp : ʵ���ļ�

#include "stdafx.h"
#include "..\include\KofMFCSpinButtonCtrl.h"
#include "..\include\KofStyleHelper.h"

//////////////////////////////////////////////////////////////////////////
// CKofSpinButtonCtrl

CKofMFCSpinButtonCtrl::CKofMFCSpinButtonCtrl()
{

}

CKofMFCSpinButtonCtrl::~CKofMFCSpinButtonCtrl()
{
}

BEGIN_MESSAGE_MAP(CKofMFCSpinButtonCtrl, CMFCSpinButtonCtrl)
END_MESSAGE_MAP()

void CKofMFCSpinButtonCtrl::OnDraw( CDC* pDC )
{
	ASSERT_VALID (this);
	ASSERT_VALID (pDC);

	CRect rectClient;
	GetClientRect(rectClient);

	if (GetBuddy()->GetSafeHwnd() != NULL && (FALSE || CMFCToolBarImages::m_bIsDrawOnGlass || TRUE))
	{
		CRect rectBorder(0, 0, 0, 0);		

		if (GetStyle() & UDS_ALIGNRIGHT)
		{
			rectBorder = rectClient;
			rectClient.DeflateRect(1, 1);
		}
		else if (GetStyle() & UDS_ALIGNLEFT)
		{
			rectBorder = rectClient;
			rectClient.DeflateRect(1, 1);
		}

		if (!rectBorder.IsRectEmpty())
		{
			CKofStyleHelper::GetInstance()->OnDrawEditBorder(pDC, rectBorder, m_bIsButtonHighligtedDown || m_bIsButtonHighligtedUp,
				m_bIsButtonPressedDown || m_bIsButtonPressedUp, IsWindowEnabled());
		}		
	}
	
	if (CMFCToolBarImages::m_bIsDrawOnGlass || FALSE)
	{
		CDrawingManager dm (*pDC);
		dm.DrawRect(rectClient, afxGlobalData.clrWindow, (COLORREF)-1);
	}
	else
	{
		pDC->FillRect(rectClient, &afxGlobalData.brWindow);
	}

	int nState = 0;

	if (m_bIsButtonPressedUp)
	{
		nState |= AFX_SPIN_PRESSEDUP;
	}

	if (m_bIsButtonPressedDown)
	{
		nState |= AFX_SPIN_PRESSEDDOWN;
	}

	if (m_bIsButtonHighligtedUp)
	{
		nState |= AFX_SPIN_HIGHLIGHTEDUP;
	}

	if (m_bIsButtonHighligtedDown)
	{
		nState |= AFX_SPIN_HIGHLIGHTEDDOWN;
	}

	if (!IsWindowEnabled())
	{
		nState |= AFX_SPIN_DISABLED;
	}

	if (GetBuddy()->GetSafeHwnd())
	{
		CKofStyleHelper::GetInstance()->OnDrawSpinButtons (
			pDC, rectClient, nState, (GetStyle() & UDS_HORZ) == UDS_HORZ, this);
	}
	else
	{
		CMFCVisualManager::GetInstance()->OnDrawSpinButtons (
			pDC, rectClient, nState, (GetStyle() & UDS_HORZ) == UDS_HORZ, this);
	}
}

LRESULT CKofMFCSpinButtonCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT nRet = CMFCSpinButtonCtrl::WindowProc(message, wParam, lParam);
	if (message == UDM_SETBUDDY)
	{
		if (GetBuddy()->GetSafeHwnd())
		{
			CRect rc;
			GetWindowRect(rc);
			if (GetParent()->GetSafeHwnd())
			{
				GetParent()->ScreenToClient(rc);
				rc.left += 1;
				MoveWindow(rc, FALSE);
			}
		}
	}
	return nRet;
}

void CKofMFCSpinButtonCtrl::PreSubclassWindow()
{
	if (GetBuddy()->GetSafeHwnd())
	{
		CRect rc;
		GetWindowRect(rc);
		if (GetParent()->GetSafeHwnd())
		{
			GetParent()->ScreenToClient(rc);
			rc.left += 1;
			MoveWindow(rc, FALSE);
		}
	}
	CMFCSpinButtonCtrl::PreSubclassWindow();
}
