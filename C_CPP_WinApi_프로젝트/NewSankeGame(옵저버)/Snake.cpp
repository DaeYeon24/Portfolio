#include "Snake.h"
#include "Alarm.h"

Snake::Snake()
{
	m_iCount = 0;
	m_iSpeed = SNAKESPEED;
	m_iOldClock = clock();
	m_alarmState = false;
	m_Alarm = NULL;
}

list<LIST_BODY>::iterator Snake::GetHead()
{
	return m_Head;
}

void Snake::SetAlarm(Alarm* alarm, bool alarmstate)
{
	m_Alarm = alarm;
	m_alarmState = alarmstate;
	alarm->SetPlayer(this);
}

void Snake::Notify(string name)
{
	if (m_alarmState)
	{
		RED
		Draw().NotifyTextXY(name + " 이(가) 나타났습니다!");
		ORIGINAL
	}
}

void Snake::StartSnake()
{
	DrawSnake(m_Head->m_ix, m_Head->m_iy);
}

void Snake::GrowSnake()
{
	LIST_BODY New;
	m_iCount++;
	if (m_iCount == 1)
	{
		//리스트
		New.m_ix = WIDTH / 2;
		New.m_iy = HEIGHT / 2;
		New.m_Direction = NULL;
		New.m_LastDirection = NULL;
		m_list.push_back(New);
		m_Head = m_list.begin();
	}
	else
	{
		//리스트
		list<LIST_BODY>::iterator tail;
		tail = m_list.end();
		tail--;
		New.m_ix = tail->m_iBeforeX;
		New.m_iy = tail->m_iBeforeY;
		m_list.push_back(New);
	}
}

void Snake::DrawSnake(int x, int y)
{
	int tmp_x, tmp_y;
	gotoxy(x, y);
	cout << HEAD;
	list<LIST_BODY>::iterator body = m_Head;
	list<LIST_BODY>::iterator end = m_list.end();
	end--;
	if (m_iCount != 1) // 리스트
	{
		tmp_x = body->m_iBeforeX;
		tmp_y = body->m_iBeforeY;
		body++;
		while (1)
		{
			EraseSnake(body);
			body->m_ix = tmp_x;
			body->m_iy = tmp_y;
			gotoxy(body->m_ix, body->m_iy);
			cout << TAIL;
			if (body == end)
				return;
			else
			{
				tmp_x = body->m_iBeforeX;
				tmp_y = body->m_iBeforeY;
				body++;
			}
		}
	}
}

void Snake::EraseSnake(list<LIST_BODY>::iterator CurPosition) // 리스트
{
	gotoxy(CurPosition->m_ix, CurPosition->m_iy);
	cout << "  ";
	CurPosition->m_iBeforeX = CurPosition->m_ix;
	CurPosition->m_iBeforeY = CurPosition->m_iy;
}

void Snake::Input(char key) // 리스트
{
	switch (key)
	{
	case LEFT:
		if (m_Head->m_LastDirection == RIGHT)
			break; /*반대 방향 금지 코드*/
		m_Head->m_Direction = key;
		break;
	case RIGHT:
		if (m_Head->m_LastDirection == LEFT)
			break;
		m_Head->m_Direction = key;
		break;
	case UP:
		if (m_Head->m_LastDirection == DOWN)
			break;
		m_Head->m_Direction = key;
		break;
	case DOWN:
		if (m_Head->m_LastDirection == UP)
			break;
		m_Head->m_Direction = key;
		break;
	}
}

int Snake::Move(Block* block, Enemy* enemy) // 리스트
{
	if (clock() - m_iOldClock >= m_iSpeed)
	{
		switch (m_Head->m_Direction)
		{
		case LEFT:
			EraseSnake(m_Head); //이전좌표 기록
			DrawSnake(--m_Head->m_ix, m_Head->m_iy); //꼬리까지 드로우
			m_Head->m_LastDirection = m_Head->m_Direction;
			break;
		case RIGHT:
			EraseSnake(m_Head);
			DrawSnake(++m_Head->m_ix, m_Head->m_iy);
			m_Head->m_LastDirection = m_Head->m_Direction;
			break;
		case UP:
			EraseSnake(m_Head);
			DrawSnake(m_Head->m_ix, --m_Head->m_iy);
			m_Head->m_LastDirection = m_Head->m_Direction;
			break;
		case DOWN:
			EraseSnake(m_Head);
			DrawSnake(m_Head->m_ix, ++m_Head->m_iy);
			m_Head->m_LastDirection = m_Head->m_Direction;
			break;
		}
		m_iOldClock = clock();
		if (CheckTail(enemy) == DEAD)
			return DEAD;
		if (block->CheckBlock(m_Head->m_ix, m_Head->m_iy) == PREY)
		{
			GrowSnake();
			if (m_iSpeed >= MAXIMUM)
				m_iSpeed -= 10;
			return PREY;
		}
		else if (block->CheckBlock(m_Head->m_ix, m_Head->m_iy) == DEAD)
			return DEAD;
		else
			return ING;
	}
	return ING;
}

int Snake::CheckTail(Enemy* enemy)
{
	list<LIST_BODY>::iterator end = m_list.end();
	end--;
	if (m_iCount != 1)
	{
		list<LIST_BODY>::iterator iter = m_Head;
		iter++;
		while (1)
		{
			if (enemy->IsAppear())
			{
				if ((*enemy->GetHead()).m_ix == iter->m_ix && (*enemy->GetHead()).m_iy == iter->m_iy)
					return DEAD;
			}
			if (m_Head->m_ix == iter->m_ix && m_Head->m_iy == iter->m_iy)
				return DEAD;
			else
			{
				if (iter == end)
					return ING;
				else
					iter++;
			}
		}
	}
}

Snake::~Snake()
{}