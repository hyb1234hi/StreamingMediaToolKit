
// StreamingMediaToolsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "pxRTMPAnalyzerDlg.h"
#include "pxRTSPAnalyzerDlg.h"
#include "afxwin.h"

// CStreamingMediaToolsDlg �Ի���
class CStreamingMediaToolsDlg : public CDialogEx
{
// ����
public:
	CStreamingMediaToolsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STREAMINGMEDIATOOLS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	CPxRTMPAnalyzerDlg *m_pRTMPAnalyzerDlg;
	CPxRTSPAnalyzerDlg *m_pRTSPAnalyzerDlg;
    
public:
	CTabCtrl m_TabCtrl;
	afx_msg void OnNMClickTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg LRESULT AddLog2List( WPARAM wParam, LPARAM lParam );
	void OnClearLogList();
	void Init();
	void TestAddLog();
	CListBox m_listboxLogInfo;
	afx_msg void OnBnClickedButtonTest();

	CRITICAL_SECTION  m_csListBox;             // �ٽ���
};