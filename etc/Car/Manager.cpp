#include "Manager.h"

Manager::Manager()
{
	for(int i = 0; i < MAX; i++)
		m_Rabbit[i] = NULL;
}

void Manager::Floor()
{
	gotoxy(0, FOURTH_FLOOR + 4);
	cout << "4類================================================================================================4類";
	gotoxy(0, THIRD_FLOOR + 4);
	cout << "3類================================================================================================3類";
	gotoxy(0, SECOND_FLOOR + 4);
	cout << "2類================================================================================================2類";
	gotoxy(0, FIRST_FLOOR + 4);
	cout << "1類================================================================================================1類";
	gotoxy(0, FIRST_FLOOR + 5);
	cout << "謙猿 : ESC";
}

void Manager::GogoRabbit()
{
	Floor();
	int CreateClock, CurClock;
	CreateClock = clock();
	m_Rabbit[0] = new Rabbit;
	m_Rabbit[0]->SetRabbit();
	while (1)
	{
		CurClock = clock();
		if (kbhit())
		{
			if (getch() == SPACEBAR)
			{
				for (int i = 0; i < MAX; i++)
				{
					if (m_Rabbit[i] != NULL)
						m_Rabbit[i]->ChangeSpeed();
				}
			}
			else if (getch() == ESC)
				return;
		}
		if (CurClock - CreateClock >= CREATE)
		{
			for (int i = 0; i < MAX; i++)
			{
				if (m_Rabbit[i] == NULL)
				{
					m_Rabbit[i] = new Rabbit;
					m_Rabbit[i]->SetRabbit();
					break;
				}
			}
			CreateClock = CurClock;
		}
		for (int i = 0; i < MAX; i++)
		{
			if (m_Rabbit[i] != NULL)
			{
				if (m_Rabbit[i]->MoveRabbit() == false)
				{
					delete m_Rabbit[i];
					m_Rabbit[i] = NULL;
				}
			}
		}
	}
}

Manager::~Manager()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_Rabbit[i] != NULL)
		{
			delete m_Rabbit[i];
			m_Rabbit[i] = NULL;
		}
	}
}