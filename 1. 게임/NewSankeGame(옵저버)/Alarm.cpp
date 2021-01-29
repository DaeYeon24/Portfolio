#include "Alarm.h"

void Alarm::SetPlayer(Snake* player)
{
	m_player = player;
}

void Alarm::RemovePlayer()
{
	m_player = NULL;
}

void Alarm::Notification()
{
	if (m_isAppear)
		m_player->Notify(m_name);
}

void Enemy::SpawnEnemy()
{
	if (!m_isAppear && clock() - m_iOldClock >= CREATEENEMYTIME)
	{
		m_isAppear = true;
		GrowSnake();
		StartSnake();
		Notification();
	}
}

void Enemy::DrawSnake(int x, int y)
{
	RED
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
				break;
			else
			{
				tmp_x = body->m_iBeforeX;
				tmp_y = body->m_iBeforeY;
				body++;
			}
		}
	}
	ORIGINAL
}

void Enemy::RemoveEnemy()
{
	for (auto i = m_list.begin(); i != m_list.end(); i++)
		EraseTail(i);
	m_list.clear();
	m_iCount = 0;
}

void Enemy::EraseTail(list<LIST_BODY>::iterator CurPosition) // 리스트
{
	gotoxy(CurPosition->m_ix, CurPosition->m_iy);
	cout << "  ";
}

void Enemy::AUTO(Block* block)
{
	if (m_isAppear)
	{
		AutoInput();
		if (Move(block) == DEAD)
		{
			Draw().NotifyTextErase();
			m_isAppear = false;
			RemoveEnemy();
			block->DrawBlock();
			m_iOldClock = clock();
		}
	}
}

bool Enemy::IsAppear()
{
	return m_isAppear;
}

void Enemy::AutoInput()
{
	int Direction = rand() % 4;
	switch (Direction)
	{
	case 0:
		Input(LEFT);
		break;
	case 1:
		Input(RIGHT);
		break;
	case 2:
		Input(UP);
		break;
	case 3:
		Input(DOWN);
		break;
	}
}

int Enemy::Move(Block* block, Enemy* enemy) // 리스트
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