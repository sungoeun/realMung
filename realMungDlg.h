
// realMungDlg.h: 헤더 파일
//

#pragma once


// CrealMungDlg 대화 상자
class CrealMungDlg : public CDialogEx
{
private:
	CImage m_image[5]; // 이미지를 읽어서 출력할때 사용할 객체, 시츄
	CImage dry; //드라이기
	CImage cut;
	CImage cutie; //옷

	CPoint m_image_pos,dry_pos,cut_pos, cutie_pos; // 시츄의 출력 위치 , 드라이기, 가위
	CPoint m_prev_pos,dry_prev_pos,cut_prev_pos, cutie_prev_pos; // 이동 거리 계산을 위해 이전 좌표를 기억
	UINT8 m_is_clicked = 0, dry_is_clicked = 0, cut_is_clicked=0, cutie_is_clicked = 0; // 마우스 클릭 여부를 기억하는 변수(0이면 클릭안됨, 1이면 클릭중)

public:
	CrealMungDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	int K = 0;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REALMUNG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButton1();

	// 타이머
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_staticDisp;
	afx_msg void OnStnClickedStaticDisp();
	afx_msg void OnBnClickedButton2();
	int m_iCount=0;
	afx_msg void OnBnClickedButton3();
	CButton Button1;
	CButton Button2;
	CButton Button3;
//	afx_msg void OnBnClickedButton4();
//	afx_msg void OnBnClickedBtndry();
};
