#include "Word.h"

Word::Word()
{
	m_Item = NON;
	m_Display = false;
}

void Word::Start_xy()
{
	m_Display = true;
	m_X = (rand() % (WIDTH - (m_Word.length() + 1))) + 1;
	m_Y = 1;
	Draw();
}

void Word::Draw(ITEM item)
{
	if (m_Item != NON)
		PUPPLE
		if (item == ALL_BLIND)
		{
			string blind_str = "";
			for (int i = 0; i < m_Word.length(); i++)
				blind_str += "=";
			m_Interface.DrawPoint(blind_str, m_X, m_Y);
		}
		else
			m_Interface.DrawPoint(m_Word, m_X, m_Y);
	ORIGINAL
}

int Word::Drop(ITEM item)
{
	m_Interface.Erase(m_Word, m_X, m_Y++);
	Draw(item);
	if (m_X >= 15 && m_X <= 55 && m_Y >= 32 && m_Y <= 35)
		return BLIND;
	return Die();
}

ITEM Word::Safe()
{
	m_Interface.Erase(m_Word, m_X, m_Y);
	m_Display = false;
	return m_Item;
}

void Word::Random_Item()
{
	if (rand() % 5 == PICK) // 20% È®·ü
	{
		switch ((rand() % 5) + 1)
		{
		case 1:
			m_Item = SPEED_UP;
			break;
		case 2:
			m_Item = SPEED_DOWN;
			break;
		case 3:
			m_Item = ALL_STOP;
			break;
		case 4:
			m_Item = ALL_BLIND;
			break;
		case 5:
			m_Item = ALL_CLEAR;
			break;
		}
	}
	else
		m_Item = NON;
}

int Word::Die()
{
	if (m_Y >= HEIGHT - 2)
	{
		m_Interface.Erase(m_Word, m_X, m_Y);
		m_Display = false;
		return DIE;
	}
	else
		return SAFE;
}

Word::~Word()
{}