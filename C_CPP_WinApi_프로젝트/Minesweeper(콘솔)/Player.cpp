#include "Player.h"

Player::Player(int x, int y)
{
	m_Limit = new Limit(x, y);
	m_iX = x / 2;
	m_iY = y / 2;
	m_strIcon = CURSOR;
}

void Player::StartCursor()
{
	DrawCursor(m_iX, m_iY);
}

void Player::DrawCursor(int x, int y)
{
	gotoxy(x, y);
	GOLD
	cout << m_strIcon;
	ORIGINAL
	gotoxy(-1, -1);
	return;
}

STEP Player::CursorInteraction(Block** BlockManager, CURSER_INTERACTION interaction, int total)
{
	int i = 0;
	while (1)
	{
		if (BlockManager[i]->GuessXY(m_iX, m_iY))
		{
			if (interaction == CURSOR_ERASE)
			{
				BlockManager[i]->Show();
				return CONTINUE;
			}
			else if (interaction == CURSOR_SELECT)
				return BlockManager[i]->GuessWhat(BlockManager, total);
			else if (interaction == CURSOR_MARK)
				return BlockManager[i]->Mark();
		}
		else
			i++;
	}
}

STEP Player::Move(Block** BlockManager, int total)
{
	while (1)
	{
		switch (_getch())
		{
		case MARKING:
			CursorInteraction(BlockManager, CURSOR_MARK, total);
			break;
		case SELECT:
			return CursorInteraction(BlockManager, CURSOR_SELECT, total);
		case LEFT:
			if (m_iX - 1 < m_Limit->Left)
				break;
			CursorInteraction(BlockManager, CURSOR_ERASE, total);
			DrawCursor(--m_iX, m_iY);
			break;
		case RIGHT:
			if (m_iX + 1 > m_Limit->Right)
				break;
			CursorInteraction(BlockManager, CURSOR_ERASE, total);
			DrawCursor(++m_iX, m_iY);
			break;
		case UP:
			if (m_iY - 1 < m_Limit->Top)
				break;
			CursorInteraction(BlockManager, CURSOR_ERASE, total);
			DrawCursor(m_iX, --m_iY);
			break;
		case DOWN:
			if (m_iY+ 1 > m_Limit->Bottom)
				break;
			CursorInteraction(BlockManager, CURSOR_ERASE, total);
			DrawCursor(m_iX, ++m_iY);
			break;
		case ESC:
			return EXIT;
		}
	}
}

Player::~Player()
{
	if (m_Limit)
	{
		delete m_Limit;
		m_Limit = NULL;
	}
}