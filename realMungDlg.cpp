
// realMungDlg.cpp: 구현 파일
//

#include "time.h"
#include "pch.h"
#include "framework.h"
#include "realMung.h"
#include "realMungDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrealMungDlg 대화 상자


CrealMungDlg::CrealMungDlg(CWnd* pParent /*=nullptr*/) :
	 CDialogEx(IDD_REALMUNG_DIALOG, pParent), m_image_pos(415,450) , dry_pos(410,125), cut_pos(515,145)
	,cutie_pos(220, 245)
{									//  욕조에 올라간 위치610(580~640),235(205~265)
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CrealMungDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DISP, m_staticDisp);
	DDX_Control(pDX, IDC_BUTTON1, Button1);
	DDX_Control(pDX, IDC_BUTTON2, Button2);
	DDX_Control(pDX, IDC_BUTTON3, Button3);
}

BEGIN_MESSAGE_MAP(CrealMungDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON1, &CrealMungDlg::OnBnClickedButton1)
ON_WM_TIMER()
ON_STN_CLICKED(IDC_STATIC_DISP, &CrealMungDlg::OnStnClickedStaticDisp)
ON_BN_CLICKED(IDC_BUTTON2, &CrealMungDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CrealMungDlg::OnBnClickedButton3)
//ON_BN_CLICKED(IDC_BTNdry, &CrealMungDlg::OnBnClickedBtndry)
END_MESSAGE_MAP()

// CrealMungDlg 메시지 처리기

BOOL CrealMungDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	m_iCount = 0; // 타이머
	//CImage img;// 이미지를 읽는다. 240,240
	m_image[0].Load(L"mrchu.png");
	m_image[1].Load(L"chu1.png");
	m_image[2].Load(L"chu2.png");
	m_image[3].Load(L"chu3.png");
	m_image[4].Load(L"chu4.png");

	dry.Load(L"d_ry.png");
	cut.Load(L"cut.png");
	cutie.Load(L"cutie.png");
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


void CrealMungDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		m_image[0].Draw(dc, m_image_pos); // 읽은 이미지 출력 
		//m_image[1].Draw(dc, 610, 235); //욕조위 위치
		//m_image[2].Draw(dc, 390, 265); // 딸기방석위 위치값
		dry.Draw(dc, dry_pos);
		cut.Draw(dc, cut_pos);
		cutie.Draw(dc, cutie_pos);
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CrealMungDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CrealMungDlg::OnDestroy() // 윈도우 닫을 때 실행됨 
{
	CDialogEx::OnDestroy();

	m_image[0].Destroy(); // 읽은 이미지 제거하는 함수 
	m_image[1].Destroy();
	m_image[2].Destroy();
	m_image[3].Destroy();
	m_image[4].Destroy();
	dry.Destroy();
	cut.Destroy();
	cutie.Destroy();
}


void CrealMungDlg::OnLButtonDown(UINT nFlags, CPoint point) //마우스 클릭
{
	if (!m_is_clicked) { // 클릭이 안되어 있는 경우에만 처리, 강아지
		//이미지가 출력된 영역을 마우스로 클릭했는지 여부를 체크한다.
		if (CRect(m_image_pos.x, m_image_pos.y, m_image_pos.x + 240, m_image_pos.y + 240).PtInRect(point)) {
			// 이 영역의 포인트 좌표가 포함되어있는지 체크
			m_is_clicked = 1; //클릭중으로 상태 변경
			m_prev_pos = point; // 이동거리 계산을 위해서 현재 좌표를 기억
			SetCapture(); //마우스 커서가 윈도우 영역을 벗어나더라도 메시지를 받도록 설정
	
		}	
	}

	if (!dry_is_clicked) { //드라이기
		if (CRect(dry_pos.x, dry_pos.y, dry_pos.x + 130, dry_pos.y + 113).PtInRect(point)) {
			dry_is_clicked = 1; //클릭중으로 상태 변경
			dry_prev_pos = point; 
			SetCapture();
		}
	}

	if (!cut_is_clicked) { //가위
		if (CRect(cut_pos.x, cut_pos.y, cut_pos.x + 109, cut_pos.y + 125).PtInRect(point)) {
			cut_is_clicked = 1; //클릭중으로 상태 변경
			cut_prev_pos = point;
			SetCapture();
		}
	}

	if (!cutie_is_clicked) { //옷
		if (CRect(cutie_pos.x, cutie_pos.y, cutie_pos.x + 109, cutie_pos.y + 125).PtInRect(point)) {
			cutie_is_clicked = 1; //클릭중으로 상태 변경
			cutie_prev_pos = point;
			SetCapture();
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CrealMungDlg::OnLButtonUp(UINT nFlags, CPoint point) {
	
	if (m_is_clicked == 1) { // 클릭된 경우에만 처리
		m_is_clicked = 0; // 클릭이 해제되었음으로 상태 변경
		ReleaseCapture(); //SetCapture 상태를 해제
	}
	// 욕조위치에 드래그하면 깨끗 멍 출력 
	int a, b;
	a = m_image_pos.x;
	b = m_image_pos.y;
	
	if (a >= 530 && a <= 700 && b >= 180 && b <= 290) { // 욕조 위치
		CPaintDC dc(this);
		m_image[0] = m_image[1];
		m_image[1].Draw(dc, m_image_pos); //  깨끗 멍 출력
	}

	if (a >= 340 && a <= 490 && b >= 385 && b <= 515 && m_image[4] == m_image[3]) { //멍멍이 처음 위치
		K = 1;
	}
	if (K == 1) {
		MessageBox(_T("성공"), _T("끝!"));
		K = 0;
		CDialogEx::OnOK(); // 프로그램 종료 창 닫기.

	}
	
	//드라이
	if (dry_is_clicked == 1) {
		dry_is_clicked = 0;
		ReleaseCapture(); 
	}
	// 드라이 슈에 드래그 하면 말린멍
	int c,d;
	c = dry_pos.x;
	d = dry_pos.y;
	if (c >= 0&& c <= 150 && d >= 470&& d <= 530) { //슈 손위치
		CPaintDC dc(this);
		m_image[0] = m_image[1] = m_image[2];
		m_image[2].Draw(dc, m_image_pos); //  말린 멍 출력
		dry_pos.x = 410;
		dry_pos.y = 125;
	}

	// 가위
	if (cut_is_clicked == 1) {
		cut_is_clicked = 0;
		ReleaseCapture();
	}
	
	int e, f;
	e = cut_pos.x;
	f = cut_pos.y;
	if (e >= 0 && e <= 150 && f >= 470 && f <= 530) { // 슈 손위치
		CPaintDC dc(this);
		m_image[0] = m_image[1] = m_image[2] = m_image[3];
		m_image[3].Draw(dc, m_image_pos); //  깨끗 멍 출력
		cut_pos.x = 515;
		cut_pos.y = 145;
	}
	
	// 옷
	if (cutie_is_clicked == 1) {
		cutie_is_clicked = 0;
		ReleaseCapture();
	}
	int g, h;
	g = cutie_pos.x;
	h = cutie_pos.y;
	if (g >= 0 && g <= 150 && h >= 470 && h <= 530) { // 슈 손위치
		CPaintDC dc(this);
		m_image[0] = m_image[1] = m_image[2] = m_image[3] = m_image[4];
		m_image[4].Draw(dc, m_image_pos); //  옷입은 멍 출력
		cutie_pos.x = 220;
		cutie_pos.y = 245;

	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CrealMungDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_is_clicked == 1) { // 클릭된 경우에만 처리
		m_image_pos += point - m_prev_pos; // 이동 거리를 m_image_pos 반영
		m_prev_pos = point; // 이동 거리 계산을 위해서 현재 좌표를 기억
		Invalidate(); // 화면을 갱신해서 이미지가 이동된 위치에 출력되도록 한다.  
	}

	if (dry_is_clicked == 1) { // 드라이기
		dry_pos += point -dry_prev_pos; 
		dry_prev_pos = point; 
		Invalidate(); 
	} 

	if (cut_is_clicked == 1) { //가위
		CPaintDC dc(this);
		cut_pos += point - cut_prev_pos;
		cut_prev_pos = point;
		Invalidate();
	} 

	if (cutie_is_clicked == 1) { //옷
		CPaintDC dc(this);
		cutie_pos += point - cutie_prev_pos;
		cutie_prev_pos = point;
		Invalidate();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


// 배경 이미지
BOOL CrealMungDlg::OnEraseBkgnd(CDC* pDC)
{

	CPngImage image;
	image.Load(IDB_PNGbk, nullptr);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&image);

	pDC->BitBlt(0, 0, 1200, 900, &dc, 0, 0, SRCCOPY);   //????????? 배경 만들기  , 크기
	dc.SelectObject(pOldBitmap);
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}


// 게임 방법 설명_ 버튼
void CrealMungDlg::OnBnClickedButton1()
{

	MessageBox(_T("1. 미용순서는 씻기->드라이/컷팅->꾸미기 순서로 진행한다.")
		_T("\n2. 드라이기,가위,옷은 슈(사람)의 손에 쥐어준다.")
		_T("\n3. 옷까지 입은 강아지를 처음 위치인 방석위에 올려두면 게임 클리어!")
		_T("\n4. 제한시간은 30초!! 게임시작을 누르면 시작한다.")
		, _T("게임방법"));

}


// 타이머 
void CrealMungDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString sTxt;
	switch (nIDEvent)
	{
	case 1:
		sTxt.Format(_T("%d"), m_iCount++);
		m_staticDisp.SetWindowText(sTxt);
		
		if (m_iCount == 30) {
			MessageBox(_T("타임 아웃 실패했습니다"), _T("끝!"));
			CDialogEx::OnOK(); // 프로그램 종료 창 닫기.
		}
		
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CrealMungDlg::OnStnClickedStaticDisp() //타이머 관련 함수
{
	// 
}

// 게임시작
void CrealMungDlg::OnBnClickedButton2()
{
	SetTimer(1, 1000, NULL);
	// 타이머 아이디, 시간 간격
}


void CrealMungDlg::OnBnClickedButton3()
{
	// 종료
	KillTimer(1); // 타이머아이디
}


//	Sleep(3000);
