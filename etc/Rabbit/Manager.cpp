#include "Manager.h"

Manager::Manager()
{
	m_Rabbit_Front = NULL;
	m_Rabbit_Rear = NULL;
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
}

void Manager::AppearRabbit()
{
	Rabbit* tmp = new Rabbit;
	if (m_Rabbit_Front == NULL)
		m_Rabbit_Front = tmp;
	else
		m_Rabbit_Rear->SetNext(tmp);
	tmp->SetRabbit();
	m_Rabbit_Rear = tmp;
}

void Manager::DisappearRabbit()
{
	if (m_Rabbit_Front != NULL)
	{
		Rabbit* tmp = m_Rabbit_Front;
		m_Rabbit_Front = tmp->GetNext();
		delete tmp;
	}
}

void Manager::MoveAll()
{
	bool MoveFlag;
	if (m_Rabbit_Front != NULL)
	{
		Rabbit* tmp = m_Rabbit_Front;
		while (tmp != NULL)
		{
			MoveFlag = tmp->MoveRabbit();
			tmp = tmp->GetNext();
			if (MoveFlag == false)
				DisappearRabbit();
		}
	}
}

void Manager::GogoRabbit()
{
	Floor();
	int CreateClock, CurClock;
	CreateClock = clock();
	while (1)
	{
		CurClock = clock();
		if (CurClock - CreateClock >= CREATETIME)
		{
			AppearRabbit();
			CreateClock = CurClock;
		}
		MoveAll();
	}
}

Manager::~Manager()
{}


//if (kbhit())
//{
//	if (getch() == SPACEBAR)
//	{
//		for (int i = 0; i < MAX; i++)
//		{
//			if (m_Rabbit[i] != NULL)
//				m_Rabbit[i]->ChangeSpeed();
//		}
//	}
//	else if (getch() == ESC)
//		return;
//}
