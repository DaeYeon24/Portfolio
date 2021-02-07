#include "Character.h"

Character::Character()
{
	m_strChar = "♤";
}

void Character::CharSetting(int Start_x, int Start_y, int Width, int Height)
{
	m_iCharx = Start_x + (Width / 2);
	m_iChary = Start_y + (Height / 2);
	m_iarrLimit[LIMIT_LEFT] = m_iCharx - (Width / 2);
	m_iarrLimit[LIMIT_RIGHT] = m_iCharx + (Width / 2);
	m_iarrLimit[LIMIT_UP] = m_iChary - (Height / 2);
	m_iarrLimit[LIMIT_DOWN] = m_iChary + (Height / 2);
	if (Width % 2 == 0) //벽과 안겹치게...
		m_iarrLimit[LIMIT_RIGHT]--; //
	if (Height % 2 == 0) //
		m_iarrLimit[LIMIT_DOWN]--; //
}

void Character::Start()
{
	CharDraw(m_iCharx, m_iChary);
}

void Character::CharDraw(int x, int y)
{
	gotoxy(x, y);
	cout << m_strChar;
}

void Character::EraseChar(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
}

void Character::CharMove()
{
	while (1)
	{
		switch (getch())
		{
		case 'a':
			if (m_iCharx - 1 == m_iarrLimit[LIMIT_LEFT])
				break;
			EraseChar(m_iCharx, m_iChary);
			CharDraw(--m_iCharx, m_iChary);
			break;
		case 'd':
			if (m_iCharx + 1 == m_iarrLimit[LIMIT_RIGHT])
				break;
			EraseChar(m_iCharx, m_iChary);
			CharDraw(++m_iCharx, m_iChary);
			break;
		case 'w':
			if (m_iChary - 1 == m_iarrLimit[LIMIT_UP])
				break;
			EraseChar(m_iCharx, m_iChary);
			CharDraw(m_iCharx, --m_iChary);
			break;
		case 's':
			if (m_iChary + 1 == m_iarrLimit[LIMIT_DOWN])
				break;
			EraseChar(m_iCharx, m_iChary);
			CharDraw(m_iCharx, ++m_iChary);
			break;
		}
	}
}

Character::~Character()
{

}