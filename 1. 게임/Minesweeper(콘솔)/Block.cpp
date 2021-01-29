#include "Block.h"

bool Block::IsMine()
{
	return m_bisMine;
}

bool Block::IsOpen()
{
	return m_bisOpen;
}

bool Block::GuessXY(int x, int y)
{
	if (m_iX == x && m_iY == y)
		return true;
	else
		return false;
}

void Block::Show()
{
	gotoxy(m_iX, m_iY);
	if (m_bisOpen)
		cout << m_strIcon;
	else if (m_bMark)
	{
		RED
			cout << MARK;
		ORIGINAL
	}
	else
		cout << UNKNOWN_BLOCK;
}

STEP Block::Mark()
{
	if (!m_bisOpen)
	{
		if (m_bMark)
			m_bMark = false;
		else if(!m_bMark)
			m_bMark = true;
		Show();
	}
	return CONTINUE;
}

void Block::Open()
{
	m_bisOpen = true;
	Show();
}

STEP Block::GuessWhat(Block** BlockManager, int total)
{
	if (m_bMark)
		return CONTINUE;
	if (!IsMine())
	{
		FindEmptyBlock(BlockManager, total);
		return CONTINUE;
	}
	else
		return BOOM;
}

void EmptyBlock::FindEmptyBlock(Block** BlockManager, int total)
{
	int Count_mine = 0;
	bool Full_empty = false;
	while (1)
	{
		for (int y = m_iY - 1; y <= m_iY + 1; y++)
		{
			for (int x = m_iX - 1; x <= m_iX + 1; x++)
			{
				if (x == m_iX && y == m_iY)
					continue;
				for (int i = 0; i < total; i++)
				{
					if (BlockManager[i]->IsOpen() == false && BlockManager[i]->GuessXY(x, y))
					{
						if (Full_empty)
						{
							BlockManager[i]->Open();
							BlockManager[i]->FindEmptyBlock(BlockManager, total);
						}
						else if (BlockManager[i]->IsMine())
							Count_mine++;
						break;
					}
				}
			}
		}
		SetIcon(Count_mine);
		Open();
		if (Full_empty == false && Count_mine == 0)
			Full_empty = true;
		else
			return;
	}
}

void Block::SetIcon(int count)
{
	switch (count)
	{
	case 0:
		return;
	case 1:
		m_strIcon = AROUND_1;
		return;
	case 2:
		m_strIcon = AROUND_2;
		return;
	case 3:
		m_strIcon = AROUND_3;
		return;
	case 4:
		m_strIcon = AROUND_4;
		return;
	case 5:
		m_strIcon = AROUND_5;
		return;
	case 6:
		m_strIcon = AROUND_6;
		return;
	case 7:
		m_strIcon = AROUND_7;
		return;
	case 8:
		m_strIcon = AROUND_8;
		return;
	}
}