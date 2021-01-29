#include "BitMap.h"

BitMap::BitMap()
{}

void BitMap::Init(HDC hdc, HINSTANCE hInst)
{
	m_MemDC = CreateCompatibleDC(hdc); //메모리 DC 생성
	m_iCount = 0; // 프로젝트폴더 내 비트맵 파일 수
	m_iSec = 0; // 인게임 카운트
	m_bisIncorrect = false; // 카드 두개 선택시 틀렸는지 확인
	m_iFirst_Select = UNSELECTED;
	m_iSecond_Select = UNSELECTED; // 1픽, 2픽
	m_pTitleBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11)); // 타이틀화면 게임시작 버튼
	m_pOldBitMap = (HBITMAP)SelectObject(m_MemDC, m_pTitleBitMap); // old 비트맵 저장.
	m_pMyBrush = (HBRUSH)GetStockObject(BLACK_BRUSH); // 검은색 브러쉬 선택
	m_pOldBrush = (HBRUSH)SelectObject(hdc, m_pMyBrush); // old 브러쉬 저장.
	ifstream load;
	TCHAR str[32];
	MyCard tmp_card;
	int tmp_num;
	while (1) // 비트맵파일 수 카운트
	{
		wsprintf(str, "%02d.bmp", m_iCount);
		load.open(str);
		if (load.is_open())
		{
			m_iCount++;
			load.close();
		}
		else
		{
			load.close();
			break;
		}
	}
	for (int j = 0; j < 2; j++) // 게임에 필요한 두쌍의 카드 벡터입력
	{
		tmp_num = 1;
		for (int i = 101; i < (101 + m_iCount); i++)
		{
			tmp_card.Animal = LoadBitmap(hInst, MAKEINTRESOURCE(i));
			//Create_Sentence(i, tmp_card.str);
			tmp_card.isBlind = true;
			tmp_card.number = tmp_num++;
			m_vecCardList.push_back(tmp_card);
		}
	}
	random_shuffle(m_vecCardList.begin(), m_vecCardList.end()); //랜덤셔플
}

void BitMap::Title(HDC hdc) // 타이틀 게임시작버튼 화면
{
	SelectObject(m_MemDC, m_pTitleBitMap);
	GetObject(m_pTitleBitMap, sizeof(m_Bitmap), &m_Bitmap);
	m_Size.cx = m_Bitmap.bmWidth;
	m_Size.cy = m_Bitmap.bmHeight;
	StretchBlt(hdc, 290, 200, 200, 150, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
}

void BitMap::InGame(HWND hWnd, HDC hdc) // 인게임 화면
{
	TCHAR str[32];
	int x = 0, y = 0;
	SetTextAlign(hdc, TA_CENTER);
	wsprintf(str, TEXT("%03d초"), m_iSec);
	TextOut(hdc, 390, 4, str, lstrlen(str));
	SelectObject(hdc, m_pMyBrush);
	Incorrect_TimeClear(hWnd);
	if (m_bisIncorrect) // 틀렸을경우 하단 문구 출력
	{
		HFONT myFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "고딕");
		HFONT oldFont = (HFONT)SelectObject(hdc, myFont);
		SetTextColor(hdc, RGB(255, 0, 0));
		wsprintf(str, TEXT("틀렸습니다."));
		TextOut(hdc, 390, 850, str, lstrlen(str));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
	}
	for (auto i = 0; i < m_vecCardList.size(); i++) //카드 나열
	{
		m_vecCardList.at(i).rt = { (x * 150 + 10), (y * 205 + 20), (x * 150 + 155), (y * 205 + 220) };
		if (m_vecCardList.at(i).isBlind)
			Rectangle(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, m_vecCardList.at(i).rt.right, m_vecCardList.at(i).rt.bottom);
		else
		{
			SelectObject(m_MemDC, m_vecCardList.at(i).Animal);
			GetObject(m_vecCardList.at(i).Animal, sizeof(m_Bitmap), &m_Bitmap);
			m_Size.cx = m_Bitmap.bmWidth;
			m_Size.cy = m_Bitmap.bmHeight;
			StretchBlt(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, 145, 200, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
		}
		x++;
		if (x % 5 == 0)
		{
			x = 0;
			y++;
		}
	}
	SelectObject(hdc, m_pOldBrush);
}

void BitMap::Time_Counting() // 인게임 기록 시간 카운트
{
	m_iSec++;
}

void BitMap::Click_Button(HWND hWnd, HDC hdc, int x, int y, bool& ingame) // 마우스 입력
{
	if (!ingame) // 타이틀화면
	{
		if (x >= 290 && x <= 490 && y >= 200 && y <= 350)
		{
			ingame = true;
			SetTimer(hWnd, 1, 1000, NULL); //인게임 시작, 시간 카운트 시작.
			InvalidateRect(hWnd, NULL, TRUE); // 타이틀에서 인게임으로 화면 전환.
			return;
		}
	}
	else // 인게임화면
	{
		if (m_bisIncorrect) // 틀릴경우 중복입력 방지
			return;
		for (auto i = 0; i < m_vecCardList.size(); i++)
		{
			if (x >= m_vecCardList.at(i).rt.left && x <= m_vecCardList.at(i).rt.right && y >= m_vecCardList.at(i).rt.top && y <= m_vecCardList.at(i).rt.bottom)
			{ // 블라인드 카드 선택 시
				if (!m_vecCardList.at(i).isBlind)
					return;
				else
				{
					m_vecCardList.at(i).isBlind = false;
					SelectObject(m_MemDC, m_vecCardList.at(i).Animal);
					GetObject(m_vecCardList.at(i).Animal, sizeof(m_Bitmap), &m_Bitmap);
					m_Size.cx = m_Bitmap.bmWidth;
					m_Size.cy = m_Bitmap.bmHeight;
					StretchBlt(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, 145, 200, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
					if (m_iFirst_Select == UNSELECTED) // 1픽
						m_iFirst_Select = i;
					else if (m_iSecond_Select == UNSELECTED) // 2픽
					{
						m_iSecond_Select = i;
						if (m_vecCardList.at(m_iFirst_Select).number == m_vecCardList.at(m_iSecond_Select).number)
						{
							m_iFirst_Select = UNSELECTED;
							m_iSecond_Select = UNSELECTED;
						}
						else
						{
							m_bisIncorrect = true; // 페널티 시작
							m_iOldClock = clock();
							InvalidateRect(hWnd, NULL, TRUE);
							return;
						}
					}
					//게임이 끝났는지 체크
					WinCheck(hWnd, ingame);
				}
				return;
			}
		}
	}
}

void BitMap::WinCheck(HWND hWnd, bool& ingame) // 윈체크 및 리셋
{
	bool AllOpen = true;
	TCHAR str[32];
	for (auto i = 0; i < m_vecCardList.size(); i++)
	{
		if (m_vecCardList.at(i).isBlind)
		{
			AllOpen = false;
			break;
		}
	}
	if (AllOpen)
	{
		KillTimer(hWnd, 1);
		wsprintf(str, "모두 맞추었습니다! 기록 : %d초", m_iSec);
		MessageBox(hWnd, str, TEXT("성공"), MB_OK);
		m_iSec = 0;
		ingame = false;
		for (auto i = 0; i < m_vecCardList.size(); i++)
		{
			m_vecCardList.at(i).isBlind = true;
		}
		random_shuffle(m_vecCardList.begin(), m_vecCardList.end());
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void BitMap::Incorrect_TimeClear(HWND hWnd) // 페널티 시간경과
{
	if (m_bisIncorrect && clock() - m_iOldClock >= INCORRECT_TIME)
	{ // 틀린상태이면서 페널티 시간이 경과했을때.
		m_vecCardList.at(m_iFirst_Select).isBlind = true;
		m_vecCardList.at(m_iSecond_Select).isBlind = true; // 1픽, 2픽을 다시 닫기
		m_iFirst_Select = UNSELECTED;
		m_iSecond_Select = UNSELECTED; // 1픽, 2픽 정보 제거
		m_bisIncorrect = false; // 페널티 해제
		InvalidateRect(hWnd, NULL, TRUE); //다시 그려주기
		return;
	}
	return;
}

//void BitMap::Create_Sentence(int index, TCHAR* str)
//{
//	switch (index)
//	{
//	case IDB_BITMAP1:
//		wsprintf(str, TEXT("강아지 입니다."));
//		break;
//	case IDB_BITMAP2:
//		wsprintf(str, TEXT("호랑이 입니다."));
//		break;
//	case IDB_BITMAP3:
//		wsprintf(str, TEXT("오리 입니다."));
//		break;
//	case IDB_BITMAP4:
//		wsprintf(str, TEXT("코끼리 입니다."));
//		break;
//	case IDB_BITMAP5:
//		wsprintf(str, TEXT("소 입니다."));
//		break;
//	case IDB_BITMAP6:
//		wsprintf(str, TEXT("말 입니다."));
//		break;
//	case IDB_BITMAP7:
//		wsprintf(str, TEXT("고양이 입니다."));
//		break;
//	case IDB_BITMAP8:
//		wsprintf(str, TEXT("원숭이 입니다."));
//		break;
//	case IDB_BITMAP9:
//		wsprintf(str, TEXT("개구리 입니다."));
//		break;
//	case IDB_BITMAP10:
//		wsprintf(str, TEXT("닭 입니다."));
//		break;
//	}
//}

BitMap::~BitMap()
{
	SelectObject(m_MemDC, m_pOldBitMap); //old비트맵 복구
	for (auto i = 0; i < m_vecCardList.size(); i++)
	{
		DeleteObject(m_vecCardList.at(i).Animal); //동물카드 해제
	}
	DeleteObject(m_pTitleBitMap); //타이틀버튼 해제
	DeleteDC(m_MemDC); // 메모리DC 해제
}
