KofPacks�Ƕ�VC2008SP1��Ribbon�����ǿ���öԻ���Ҳ�Ͷ��ĵ������ĵ�һ������ͬ��Office��ʽ��

��VS2008 SP1���ڶԻ��򹤳�ʹ�ã�
����̬�⡿
1.��"stdafx.h"�ļ���������´��룺
#include "KofPackInc.h"
2.���úø���ͷ�ļ�Ŀ¼�͸��ӿ�Ŀ¼��
3.�򿪶Ի����ļ�������������CDialog��ΪCKofDialogEx
4.��Ӧ�ó���Appʵ���ļ�����InitInstance�����У�������´��룺
CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
CKofStyleHelper::GetInstance()->SetStyle(CKofStyleHelper::KOF_CMFCVisualManagerOffice2007);
5.�������к󣬼��ɿ���Office2007��ʽ�ĶԻ���

����̬�⡿
������һ��������Դ��ͼ���Ҽ���Դ���ӣ���#include "afxribbon.rc" ֮�����
#include "KofPackRes.rc"
�������� ��Դ ���棬���Ӹ�������Ŀ¼"$(SolutionDir)Include";