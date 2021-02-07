#include "Rabbit.h"

Rabbit::Rabbit()
{
	m_iX = START_LINE + 1;
	m_iY = FOURTH_FLOOR;
	m_iSpeed = FAST;
	m_iOldClock = clock();
	m_Next = NULL;
}

void Rabbit::DrawRabbit(int x, int add)
{
	gotoxy(x, 0 + add);
	cout << "() ()";
	gotoxy(x, 1 + add);
	cout << "(-_-)";
	if (add == THIRD_FLOOR || add == FIRST_FLOOR)
	{
		gotoxy(x - 1, 2 + add);
		cout << "¦¦( )¦¤";
		gotoxy(x, 3 + add);
		cout << " <¦¦";
	}
	else
	{
		gotoxy(x - 1, 2 + add);
		cout << "¦£( )¦¥";
		gotoxy(x, 3 + add);
		cout << "¦¥ >";
	}
}

void Rabbit::EraseRabbit(int x, int add)
{
	gotoxy(x, 0 + add);
	cout << "      ";
	gotoxy(x, 1 + add);
	cout << "      ";
	gotoxy(x - 1, 2 + add);
	cout << "      ";
	gotoxy(x, 3 + add);
	cout << "      ";
}

void Rabbit::ChangeSpeed()
{
	if (m_iSpeed == SLOW)
		m_iSpeed = FAST;
	else
		m_iSpeed = SLOW;
}

void Rabbit::SetRabbit()
{
	DrawRabbit(m_iX, m_iY);
}

bool Rabbit::MoveRabbit()
{
	if (clock() - m_iOldClock >= m_iSpeed)
	{
		if (m_iY == THIRD_FLOOR || m_iY == FIRST_FLOOR)
		{
			EraseRabbit(m_iX--, m_iY);
			DrawRabbit(m_iX, m_iY);
		}
		else
		{
			EraseRabbit(m_iX++, m_iY);
			DrawRabbit(m_iX, m_iY);
		}
		if (m_iX - 1 < START_LINE || m_iX + 1 > END_LINE)
		{
			EraseRabbit(m_iX, m_iY);
			m_iY += 5;
			if (m_iX - 1 < START_LINE)
				m_iX = START_LINE + 1;
			else
				m_iX = END_LINE - 1;
		}
		m_iOldClock = clock();
		return true;
	}
	if (m_iY + 5 >= 25)
	{
		EraseRabbit(m_iX, m_iY);
		return false;
	}
	return true;
}

Rabbit::~Rabbit()
{

}