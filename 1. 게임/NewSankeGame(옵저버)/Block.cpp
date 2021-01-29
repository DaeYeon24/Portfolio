#include "Block.h"

Block::Block()
{
	for (int i = 0; i < PREYMAX; i++)
		m_LifeBlock[i] = NULL;
	for (int i = 0; i < DEADMAX; i++)
		m_DeathBlock[i] = NULL;
	m_CreateClock = clock();
}

void Block::DrawWall()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2 + 1);
	system(buf);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y == 0 || y == HEIGHT - 1)
			{
				cout << "¢Ì";
			}
			else if (x == 0 || x == WIDTH - 1)
			{
				cout << "¢Ì";
			}
			else
				cout << "  ";
		}
	}
}

void Block::SetDeathBlock()
{
	for (int i = 0; i < DEADMAX;)
	{
		m_DeathBlock[i] = new Point;
		m_DeathBlock[i]->m_ix = (rand() % (WIDTH - 2)) + 1;
		m_DeathBlock[i]->m_iy = (rand() % (HEIGHT - 2)) + 1;
		if (m_DeathBlock[i]->m_ix == WIDTH / 2 && m_DeathBlock[i]->m_iy == HEIGHT / 2)
			continue;
		else
			i++;
	}
}

void Block::SetLifeBlock()
{
	int empty, tmp_x, tmp_y;
	if (clock() - m_CreateClock >= CREATETIME)
	{
		for (empty = 0; empty < PREYMAX; empty++)
		{
			if (m_LifeBlock[empty] == NULL)
			{
				while (1)
				{
					tmp_x = (rand() % (WIDTH - 2)) + 1;
					tmp_y = (rand() % (HEIGHT - 2)) + 1;
					if (CheckBlock(tmp_x, tmp_y, PREY) == DEAD)
						continue;
					else
					{
						m_LifeBlock[empty] = new Point;
						m_LifeBlock[empty]->m_ix = tmp_x;
						m_LifeBlock[empty]->m_iy = tmp_y;
						DrawBlock(PREY, m_LifeBlock[empty]->m_ix, m_LifeBlock[empty]->m_iy);
						m_CreateClock = clock();
						return;
					}
				}
			}
		}
		return;
	}
	else
		return;
}

void Block::DrawBlock(int what, int x, int y)
{
	if (what == PREY)
	{
		gotoxy(x, y);
		cout << "¢½";
	}
	else
	{
		for (int i = 0; i < DEADMAX; i++)
		{
			gotoxy(m_DeathBlock[i]->m_ix, m_DeathBlock[i]->m_iy);
			cout << "¢Ã";
		}
	}
}

void Block::EraseBlock(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
}

int Block::CheckBlock(int x, int y, int what)
{
	if (x == 0 || x == WIDTH - 1)
		return DEAD;
	else if (y == 0 || y == HEIGHT - 1)
		return DEAD;
	for (int i = 0; i < DEADMAX; i++)
	{
		if (x == m_DeathBlock[i]->m_ix && y == m_DeathBlock[i]->m_iy)
			return DEAD;
	}
	if (what == PREY)
		return ING;
	for (int i = 0; i < PREYMAX; i++)
	{
		if (m_LifeBlock[i] != NULL)
		{
			if (x == m_LifeBlock[i]->m_ix && y == m_LifeBlock[i]->m_iy)
			{
				delete m_LifeBlock[i];
				m_LifeBlock[i] = NULL;
				return PREY;
			}
		}
	}
	return ING;
}

Block::~Block()
{
	for (int i = 0; i < PREYMAX; i++)
	{
		if (m_LifeBlock[i] != NULL)
			delete m_LifeBlock[i];
	}
	for (int i = 0; i < DEADMAX; i++)
	{
		if (m_DeathBlock[i] != NULL)
			delete m_DeathBlock[i];
	}
}