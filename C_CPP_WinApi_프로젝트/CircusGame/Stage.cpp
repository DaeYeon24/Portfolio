#include "Stage.h"
#include "Character.h"

Stage::~Stage()
{
	SelectObject(m_MemDC, m_OldBitMap);
	DeleteDC(m_MemDC);
	DeleteObject(m_TrackBitMap);
	DeleteObject(m_EndBitMap);
	DeleteObject(m_AudienceBitMap[0]);
	DeleteObject(m_AudienceBitMap[1]);
	if (!m_vecHurdleList.empty())
	{
		for (auto iter = m_vecHurdleList.begin(); iter != m_vecHurdleList.end(); iter++)
		{
			delete* iter;
		}
		m_vecHurdleList.clear();
	}
	if (!m_vecRingList.empty())
	{
		for (auto iter = m_vecRingList.begin(); iter != m_vecRingList.end(); iter++)
		{
			delete* iter;
		}
		m_vecRingList.clear();
	}
	if (!m_vecDecoList.empty())
	{
		for (auto iter = m_vecDecoList.begin(); iter != m_vecDecoList.end(); iter++)
		{
			delete* iter;
		}
		m_vecDecoList.clear();
	}
}

void Stage::Init(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_TrackBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\back.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_AudienceBitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\back_normal0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_AudienceBitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\back_normal1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_EndBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\end.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_TrackBitMap);
	m_fBackGroundX = 0.0f;
	m_iDistance = 0;
	m_iLastDistance = 0;
	m_iScore = 0;
	m_bGameClear = false;
	m_bShowEnd = false;
	m_fEndX = 1200.0f;
	m_rtFinishArea = { (LONG)m_fEndX - 40, 400, (LONG)m_fEndX + 500, 610 };
	m_iCurMotion = 0;
	m_iOldMovement = clock();
}

int Stage::Get_Score()
{
	return m_iScore;
}

void Stage::Add_CashScore()
{
	m_iScore += 500;
}

void Stage::Progress_Ring(PROGRESS progress, float oneframe)
{
	for (auto iter = m_vecRingList.begin(); iter != m_vecRingList.end();)
	{
		if (!(*iter)->Coming(progress, oneframe))
		{
			delete* iter;
			iter = m_vecRingList.erase(iter);
			m_iScore += 150;
		}
		else
			iter++;
	}
}

void Stage::Progress(PROGRESS progress, float oneframe)
{
	switch (progress)
	{
	case FORWARD:
		if (m_iLastDistance <= 10000) ////////////////////////////////
		{
			if (m_fBackGroundX <= -100.0f)
				m_fBackGroundX = 0.0f;
			m_fBackGroundX -= 200.0f * oneframe;
			m_iDistance++;
			if (m_iDistance >= m_iLastDistance)
			{
				m_iLastDistance++;
				m_iScore++;
			}
			if (m_iLastDistance >= 9700)
			{
				m_bShowEnd = true;
				m_fEndX -= 200.0f * oneframe;
				m_rtFinishArea = { (LONG)m_fEndX - 40, 400, (LONG)m_fEndX + 500, 610 };
			}
		}
		break;
	case BACKWARD:
		if (m_iDistance > 0 && m_iLastDistance <= 10000)
		{
			if (m_fBackGroundX >= 0.0f)
				m_fBackGroundX = -100.0f;
			m_fBackGroundX += 50.0f * oneframe;
			m_iDistance--;
			if (m_iLastDistance >= 9700)
			{
				m_fEndX += 50.0f * oneframe;
				m_rtFinishArea = { (LONG)m_fEndX - 40, 400, (LONG)m_fEndX + 500, 610 };
			}
		}
		break;
	}
	if (m_iDistance > 0 && m_iLastDistance <= 10000)
	{
		for (auto iter = m_vecDecoList.begin(); iter != m_vecDecoList.end();)
		{
			if (!(*iter)->Coming(progress, oneframe))
			{
				delete* iter;
				iter = m_vecDecoList.erase(iter);
			}
			else
				iter++;
		}
		for (auto iter = m_vecHurdleList.begin(); iter != m_vecHurdleList.end();)
		{
			if (!(*iter)->Coming(progress, oneframe))
			{
				delete* iter;
				iter = m_vecHurdleList.erase(iter);
				m_iScore += 150;
			}
			else
				iter++;
		}
	}
}

void Stage::Draw(HDC hdc, bool frontdraw)
{
	if (frontdraw)
	{
		for (auto i = 0; i < m_vecRingList.size(); i++)
		{
			m_vecRingList.at(i)->FrontDraw(hdc);
		}
	}
	else
	{
		SelectObject(m_MemDC, m_TrackBitMap);
		GetObject(m_TrackBitMap, sizeof(BITMAP), &m_BitMapInfo);
		StretchBlt(hdc, 0, 350, WIDTH, HEIGHT / 2, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, SRCCOPY);
		if (m_bGameClear)
		{
			if (clock() - m_iOldMovement >= UPDATE_TIME)
			{
				if (m_iCurMotion == 0)
					m_iCurMotion = 1;
				else if (m_iCurMotion == 1)
					m_iCurMotion = 0;
				m_iOldMovement = clock();
			}
		}
		SelectObject(m_MemDC, m_AudienceBitMap[m_iCurMotion]);
		GetObject(m_AudienceBitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
		float lastX = m_fBackGroundX;
		while (1)
		{
			StretchBlt(hdc, m_fBackGroundX, 150, 102, 210, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, SRCCOPY);
			m_fBackGroundX += 100;
			if (m_fBackGroundX >= 1200)
			{
				m_fBackGroundX = lastX;
				break;
			}
		}
		if (m_bShowEnd)
		{
			SelectObject(m_MemDC, m_EndBitMap);
			GetObject(m_EndBitMap, sizeof(BITMAP), &m_BitMapInfo);
			TransparentBlt(hdc, m_fEndX, 550, 150, 60, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
		}
		for (auto i = 0; i < m_vecDecoList.size(); i++)
		{
			m_vecDecoList.at(i)->Draw(hdc);
		}
		for (auto i = 0; i < m_vecHurdleList.size(); i++)
		{
			m_vecHurdleList.at(i)->Draw(hdc);
		}
		for (auto i = 0; i < m_vecRingList.size(); i++)
		{
			m_vecRingList.at(i)->Draw(hdc);
		}
	}
}

void Stage::Update(HDC hdc, float oneframe)
{
	Create_Trap(hdc);
	Create_Deco(hdc);
}

void Stage::Create_Deco(HDC hdc)
{
	Deco* tmp_deco;
	if (m_iLastDistance == 0 && m_vecDecoList.empty())
	{
		tmp_deco = new Miter(hdc, 0);
		m_vecDecoList.push_back(tmp_deco);
	}
	if (m_iLastDistance != 0 && m_iLastDistance <= 9500 && m_iLastDistance % 1000 == 0)
	{
		tmp_deco = new Miter(hdc, m_iLastDistance);
		m_vecDecoList.push_back(tmp_deco);
	}
	if (m_iLastDistance == 9750)
	{
		tmp_deco = new Miter(hdc, 10000);
		m_vecDecoList.push_back(tmp_deco);
	}
	if (m_iLastDistance != 0 && m_iLastDistance <= 9500 && m_iLastDistance % 1500 == 0)
	{
		tmp_deco = new Elephant(hdc);
		m_vecDecoList.push_back(tmp_deco);
	}
}

void Stage::Create_Trap(HDC hdc)
{
	Hurdle* tmp_hurdle;
	Ring* tmp_ring;
	if (m_iLastDistance <= 9500)
	{
		if (m_vecRingList.size() < 3)
		{
			if (!m_vecRingList.empty())
			{
				if (m_vecRingList.at(m_vecRingList.size() - 1)->Get_X() <= 900.0f && rand() % 100 == 0)
				{
					tmp_ring = new Ring(hdc);
					m_vecRingList.push_back(tmp_ring);
				}
			}
			else
			{
				if (rand() % 100 == 0)
				{
					tmp_ring = new Ring(hdc);
					m_vecRingList.push_back(tmp_ring);
				}
			}
		}
		if (m_vecHurdleList.size() < 3)
		{
			if (!m_vecHurdleList.empty())
			{
				if (m_vecHurdleList.at(m_vecHurdleList.size() - 1)->Get_X() <= 900.0f && rand() % 100 == 0)
				{
					tmp_hurdle = new Hurdle(hdc);
					m_vecHurdleList.push_back(tmp_hurdle);
				}
			}
			else
			{
				if (rand() % 100 == 0)
				{
					tmp_hurdle = new Hurdle(hdc);
					m_vecHurdleList.push_back(tmp_hurdle);
				}
			}
		}
	}
}

RECT Trap::Get_Area()
{
	return m_rtArea;
}

float Trap::Get_X()
{
	return m_fX;
}

vector<Hurdle*>	Stage::Get_TrapList_Hurdle()
{
	return m_vecHurdleList;
}

vector<Ring*>	Stage::Get_TrapList_Ring()
{
	return m_vecRingList;
}

RECT Stage::Get_FinishArea()
{
	return m_rtFinishArea;
}

bool Stage::IsShowEnd()
{
	return m_bShowEnd;
}

void Stage::Game_Clear()
{
	m_bGameClear = true;
}

bool Stage::IsTrackFinish()
{
	if (m_iLastDistance >= 10000)
		return true;
	else
		return false;
}

Hurdle::Hurdle(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_BitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\hurdle0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\hurdle1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_iCurMotion = 0;
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_BitMap[m_iCurMotion]);
	m_fX = 1200.0f;
	m_rtArea = { (LONG)m_fX + 10, 550, (LONG)m_fX + 70, 605 };
	m_iOldClock = clock();
}

Hurdle::~Hurdle()
{
	SelectObject(m_MemDC, m_OldBitMap);
	DeleteObject(m_BitMap[0]);
	DeleteObject(m_BitMap[1]);
	DeleteDC(m_MemDC);
}

Ring::Ring(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_BitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\ring0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\ring1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_FrontBitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\ring_back0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_FrontBitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\ring_back1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CashBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\ring_cash.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_iCurMotion = 0;
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_BitMap[m_iCurMotion]);
	m_fX = 1200.0f;
	m_rtArea = { (LONG)m_fX, 350, (LONG)m_fX + 50, 530 };
	m_rtSafeZone = { (LONG)m_fX, 360, (LONG)m_fX + 50, 520 };
	m_iOldClock = clock();
	if (rand() % 5 == 0)
		m_bHaveCash = true;
	else
		m_bHaveCash = false;
}

Ring::~Ring()
{
	SelectObject(m_MemDC, m_OldBitMap);
	DeleteObject(m_BitMap[0]);
	DeleteObject(m_BitMap[1]);
	DeleteObject(m_FrontBitMap[0]);
	DeleteObject(m_FrontBitMap[1]);
	DeleteObject(m_CashBitMap);
	DeleteDC(m_MemDC);
}

void Hurdle::Draw(HDC hdc)
{
	if (clock() - m_iOldClock >= UPDATE_TIME)
	{
		if(m_iCurMotion == 0)
			m_iCurMotion = 1;
		else if (m_iCurMotion == 1)
			m_iCurMotion = 0;
		m_iOldClock = clock();
	}
	SelectObject(m_MemDC, m_BitMap[m_iCurMotion]);
	GetObject(m_BitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
	TransparentBlt(hdc, m_fX, 525, 80, 80, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
}

void Ring::Draw(HDC hdc)
{
	if (clock() - m_iOldClock >= UPDATE_TIME)
	{
		if (m_iCurMotion == 0)
			m_iCurMotion = 1;
		else if (m_iCurMotion == 1)
			m_iCurMotion = 0;
		m_iOldClock = clock();
	}
	if (m_bHaveCash)
	{
		SelectObject(m_MemDC, m_CashBitMap);
		GetObject(m_CashBitMap, sizeof(BITMAP), &m_BitMapInfo);
		TransparentBlt(hdc, m_fX, 350, 50, 180, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
	}
	else
	{
		SelectObject(m_MemDC, m_BitMap[m_iCurMotion]);
		GetObject(m_BitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
		TransparentBlt(hdc, m_fX, 350, 50, 180, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
	}
}

void Ring::FrontDraw(HDC hdc)
{
	SelectObject(m_MemDC, m_FrontBitMap[m_iCurMotion]);
	GetObject(m_FrontBitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
	TransparentBlt(hdc, m_fX + 25, 350, 25, 180, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
}

bool Ring::IsHaveCash()
{
	if (m_bHaveCash)
	{
		m_bHaveCash = false;
		return true;
	}
	else
		return false;
}

bool Hurdle::Coming(PROGRESS progress, float deltatime)
{
	if (m_fX <= -10.0f)
		return false;
	if (progress == FORWARD)
		m_fX -= 200.0f * deltatime;
	else
		m_fX += 50.0f * deltatime;
	m_rtArea = { (LONG)m_fX + 10, 550, (LONG)m_fX + 70, 605 };
	return true;
}

bool Ring::Coming(PROGRESS progress, float deltatime)
{
	if (m_fX <= -10.0f)
		return false;
	if (progress == FORWARD)
		m_fX -= 250.0f * deltatime;
	else
		m_fX -= 125.0f * deltatime;
	m_rtArea = { (LONG)m_fX, 350, (LONG)m_fX + 50, 530 };
	m_rtSafeZone = { (LONG)m_fX, 360, (LONG)m_fX + 50, 520 };
	return true;
}

bool Ring::Character_In_SafeZone(Character* character)
{
	RECT tmp;
	RECT area = character->Get_Area();
	if (IntersectRect(&tmp, &m_rtSafeZone, &area))
		return true;
	else
		return false;
}

Deco::~Deco()
{
	SelectObject(m_MemDC, m_OldBitMap);
	DeleteObject(m_DecoBitMap);
	DeleteDC(m_MemDC);
}

bool Deco::Coming(PROGRESS progress, float deltatime)
{
	if (progress == FORWARD)
		m_fX -= 200.0f * deltatime;
	else
		m_fX += 50.0f * deltatime;
	if (m_fX <= -200.0f)
		return false;
	else
		return true;
}

void Elephant::Draw(HDC hdc)
{
	if(m_fX >= -100.0f && m_fX <= 1200.0f)
		TransparentBlt(hdc, m_fX, 150, 100, 210, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
}

void Miter::Draw(HDC hdc)
{
	TCHAR str[32];
	if (m_fX >= -100.0f && m_fX <= 1200.0f)
	{
		TransparentBlt(hdc, m_fX, 650, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
		wsprintf(str, TEXT("%d"), m_iMiter);
		TextOut(hdc, m_fX + 30, 656, str, lstrlen(str));
	}
}

Elephant::Elephant(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_DecoBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\back_deco.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_DecoBitMap);
	SelectObject(m_MemDC, m_DecoBitMap);
	GetObject(m_DecoBitMap, sizeof(BITMAP), &m_BitMapInfo);
	m_fX = 1200.0f;
}

Miter::Miter(HDC hdc, int miter)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_DecoBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\miter.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_DecoBitMap);
	SelectObject(m_MemDC, m_DecoBitMap);
	GetObject(m_DecoBitMap, sizeof(BITMAP), &m_BitMapInfo);
	m_fX = 1200.0f;
	m_iMiter = (10000 - miter) / 100;
}