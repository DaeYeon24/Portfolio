#include "Character.h"

Character::~Character()
{
	SelectObject(m_MemDC, m_OldBitMap);
	DeleteObject(m_WinBitMap[0]);
	DeleteObject(m_WinBitMap[1]);
	DeleteObject(m_CurBitMap[0]);
	DeleteObject(m_CurBitMap[1]);
	DeleteObject(m_CurBitMap[2]);
	DeleteObject(m_CurBitMap[3]);
	DeleteObject(m_LifeBitMap);
	DeleteDC(m_MemDC);
}

void Character::Init(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_WinBitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\win0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_WinBitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\win1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CurBitMap[0] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\player0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CurBitMap[1] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\player1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CurBitMap[2] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\player2.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CurBitMap[3] = (HBITMAP)LoadImage(NULL, TEXT("Circus\\die.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_LifeBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\life.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_iCurMotion = 0;
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_CurBitMap[m_iCurMotion]); // old 비트맵 저장.
	m_fX = START_X;
	m_fY = START_Y;
	m_fJumpX = JUMP_X;
	m_fJumpY = JUMP_Y;
	m_eState = IDLE;
	m_iLife = 3; // 목숨 3개
	m_bRetryCoolTime = false;
	m_rtCharacterArea = { (LONG)m_fX + 10, (LONG)m_fY + 10, (LONG)m_fX + 50, (LONG)m_fY + 50 };
	m_iOldMovement = clock();
}

void Character::Draw(HDC hdc) // 인게임 화면
{
	for (auto i = 1; i <= m_iLife; i++) // 남은 생명력 출력
	{
		SelectObject(m_MemDC, m_LifeBitMap);
		GetObject(m_LifeBitMap, sizeof(BITMAP), &m_BitMapInfo);
		TransparentBlt(hdc, 950 + (i * 50), 110, 40, 40, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
	}
	// 모션 동작
	if (m_eState == FINISH && clock() - m_iOldMovement >= UPDATE_TIME) // 게임 클리어
	{
		if (m_iCurMotion == 0)
			m_iCurMotion = 1;
		else if (m_iCurMotion == 1)
			m_iCurMotion = 0;
		m_iOldMovement = clock();
	}
	else if (m_eState != DIE && m_eState != SHOCK && clock() - m_iOldMovement >= UPDATE_TIME) // 게임 중 살아있을때
	{
		if (m_eState == RUN) // 달릴때
		{
			if (m_iCurMotion == 0)
				m_iCurMotion = 1;
			else if (m_iCurMotion == 1)
				m_iCurMotion = 2;
			else if (m_iCurMotion == 2)
				m_iCurMotion = 0;
		}
		else if (m_eState == BACKSTEP) // 뒷걸음질
		{
			if (m_iCurMotion == 0)
				m_iCurMotion = 1;
			else if (m_iCurMotion == 1)
				m_iCurMotion = 0;
		}
		else if (m_eState == JUMP) // 점프
			m_iCurMotion = 2;
		else if (m_eState == IDLE) // 가만히
			m_iCurMotion = 0;
		m_iOldMovement = clock();
	}
	else if(m_eState == SHOCK || m_eState == DIE) // 죽거나 쇼크
		m_iCurMotion = 3;
	// 출력
	if (m_eState == FINISH) // 게임 클리어
	{
		SelectObject(m_MemDC, m_WinBitMap[m_iCurMotion]);
		GetObject(m_WinBitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
	}
	else // 게임 중
	{
		SelectObject(m_MemDC, m_CurBitMap[m_iCurMotion]);
		GetObject(m_CurBitMap[m_iCurMotion], sizeof(BITMAP), &m_BitMapInfo);
	}
	TransparentBlt(hdc, m_fX, m_fY, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, m_MemDC, 0, 0, m_BitMapInfo.bmWidth, m_BitMapInfo.bmHeight, RGB(255, 0, 255));
}

void Character::Operate_Input(Stage* stage, float oneframe)
{
	if (m_eState == JUMP)
	{
		if (m_fY > START_Y)
		{
			m_fY = START_Y;
			m_fJumpY = JUMP_Y;
			m_eState = IDLE;
			return;
		}
		stage->Progress_Ring(FORWARD, oneframe);
		stage->Progress(FORWARD, oneframe);
		if (stage->IsTrackFinish())
			m_fX += m_fJumpX * oneframe;
		m_fY -= m_fJumpY * oneframe;
		m_rtCharacterArea = { (LONG)m_fX + 10, (LONG)m_fY + 10, (LONG)m_fX + 50, (LONG)m_fY + 50 };
		m_fJumpY -= 1000 * oneframe;
	}
	else
	{
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			if (m_eState != BACKSTEP)
				m_iCurMotion = 0;
			m_eState = BACKSTEP;
			stage->Progress_Ring(BACKWARD, oneframe);
			stage->Progress(BACKWARD, oneframe);
			if(stage->IsTrackFinish() && m_fX >= 0.5f)
				m_fX -= 50.0f * oneframe;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			m_eState = RUN;
			stage->Progress_Ring(FORWARD, oneframe);
			stage->Progress(FORWARD, oneframe);
			if (stage->IsTrackFinish())
				m_fX += 100.0f * oneframe;
		}
		else
		{
			m_eState = IDLE;
			stage->Progress_Ring(BACKWARD, oneframe);
		}
		m_rtCharacterArea = { (LONG)m_fX + 10, (LONG)m_fY + 10, (LONG)m_fX + 50, (LONG)m_fY + 50 };
		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			m_eState = JUMP;
			return;
		}
	}
}

void Character::Update(Stage* stage, float oneframe, bool& ingame)
{
	switch (m_eState)
	{
	case FINISH:
		if (Game_Clear(stage, oneframe))
			ingame = false;
		break;
	case SHOCK:
		Shock(oneframe);
		break;
	case DIE:
		if (Die(oneframe))
			ingame = false;
		break;
	default:
		if (m_bRetryCoolTime)
			RetryCoolDown(oneframe);
		Operate_Input(stage, oneframe);
		if(!m_bRetryCoolTime)
			Collision(stage);
		break;
	}
}

void Character::Collision(Stage* stage)
{
	RECT tmp;
	for (auto i = 0; i < stage->Get_TrapList_Hurdle().size(); i++) // 허들 충돌체크
	{
		RECT area = stage->Get_TrapList_Hurdle().at(i)->Get_Area();
		if (IntersectRect(&tmp, &m_rtCharacterArea, &area))
		{
			m_eState = SHOCK;
			m_iLife--;
			m_fRetryX = m_fX - 50.0f;
			m_fJumpY = JUMP_Y;
			return;
		}
	}
	for (auto i = 0; i < stage->Get_TrapList_Ring().size(); i++) // 링 충돌체크
	{
		RECT area = stage->Get_TrapList_Ring().at(i)->Get_Area();
		if (IntersectRect(&tmp, &m_rtCharacterArea, &area))
		{
			if (stage->Get_TrapList_Ring().at(i)->Character_In_SafeZone(this))
			{
				if (stage->Get_TrapList_Ring().at(i)->IsHaveCash())
					stage->Add_CashScore();
				continue;
			}
			else
			{
				m_eState = SHOCK;
				m_iLife--;
				m_fRetryX = m_fX - 50.0f;
				m_fJumpY = JUMP_Y;
				return;
			}
		}
	}
	if (stage->IsShowEnd())
	{
		RECT area = stage->Get_FinishArea();
		if (IntersectRect(&tmp, &m_rtCharacterArea, &area))
		{
			m_eState = FINISH;
			m_iCurMotion = 0;
			stage->Game_Clear();
			return;
		}
	}
}

bool Character::Die(float oneframe)
{
	if (m_fY > 800.0f)
		return true;
	else
	{
		m_fY -= m_fJumpY * oneframe;
		m_fJumpY -= 1000.0f * oneframe;
		return false;
	}
}

void Character::RetryCoolDown(float oneframe)
{
	static float cooltime = 0.0f;
	if (cooltime >= 2.0f)
	{
		m_bRetryCoolTime = false;
		cooltime = 0.0f;
		return;
	}
	else
		cooltime += oneframe;
}

void Character::Shock(float oneframe)
{
	static float shocktime = 0.0f;
	if (m_iLife <= 0)
	{
		m_eState = DIE;
		return;
	}
	if (m_fX <= m_fRetryX && m_fY >= START_Y)
	{
		m_fY = START_Y;
		if (shocktime >= 1.0f) // retry 대기시간.
		{
			shocktime = 0.0f;
			m_eState = IDLE;
			m_bRetryCoolTime = true;
			return;
		}
		else
			shocktime += oneframe;
	}
	else // retry 지점 이동.
	{
		if (m_fX >= m_fRetryX)
			m_fX -= 80 * oneframe;
		if (m_fY <= START_Y)
			m_fY += 80 * oneframe;
	}
	return;
}

bool Character::Game_Clear(Stage* stage, float oneframe)
{
	static float finishtime = 0.0f;
	if (m_fX >= stage->Get_FinishArea().left + 60.0f && (int)m_fY == 490)
	{
		if (finishtime >= 3.0f) // 세리머니 시간.
		{
			finishtime = 0.0f;
			return true;
		}
		else
			finishtime += oneframe;
	}
	else // finish 지점 이동.
	{
		if (m_fX <= stage->Get_FinishArea().left + 60.0f)
			m_fX += 50 * oneframe;
		if (m_fY <= 490.0f)
			m_fY += 55 * oneframe;
		else
			m_fY -= 55 * oneframe;
	}
	return false;
}

RECT Character::Get_Area()
{
	return m_rtCharacterArea;
}