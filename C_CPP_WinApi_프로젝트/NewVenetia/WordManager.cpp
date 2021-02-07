#include "WordManager.h"

WordManager::WordManager()
{
	m_Word_List = NULL;
	ReSet_Stage();
	m_Item_Status = NON;
}

void WordManager::Stage_Up()
{
	m_Stage_Level++;
	if (m_Falling_Speed > STANDARD_FALLING_SPEED)
		m_Falling_Speed -= INCREASE_FALLING_SPEED;
	if (m_Create_Speed > STANDARD_CREATE_SPEED)
		m_Create_Speed -= INCREASE_CREATE_SPEED;
	if (m_Stage_Level % STANDARD_MAX_UP == 0)
		m_Create_Max++;
}

void WordManager::ReSet_Stage()
{
	m_Stage_Level = 1;
	m_Create_Max = 2;
	m_Create_Clock = clock();
	m_Create_Speed = FIRST_CREATE_TIME;
	m_Falling_Clock = clock();
	m_Falling_Count = 0;
	m_Falling_Speed = FIRST_FALLING_TIME;
}

void WordManager::ReSet_Word(int* score)
{
	for (int i = 0; i < m_Word_Max; i++)
	{
		if (m_Word_List[i].GetDisplay())
		{
			if (score != NULL)
				*score += m_Word_List[i].GetWord().length() * 33;
			m_Word_List[i].Safe();
		}
	}
}

void WordManager::Load()
{
	ifstream load;
	string tmp;
	load.open("Word.txt");
	if (load.is_open())
	{
		load >> m_Word_Max;
		m_Word_List = new Word[m_Word_Max];
		for (int i = 0; i < m_Word_Max; i++)
		{
			load >> tmp;
			m_Word_List[i].SetWord(tmp);
		}
	}
	load.close();
}

void WordManager::Create_Word()
{
	int select;
	bool overlap = false;
	if (m_Item_Status == ALL_STOP)
		return;
	if (clock() - m_Create_Clock >= m_Create_Speed)
	{
		int create = rand() % m_Create_Max;
		for (int i = 0; i < create; )
		{
			select = rand() % m_Word_Max;
			if (m_Word_List[select].GetDisplay())
				continue;
			else
			{
				m_Word_List[select].Random_Item();
				m_Word_List[select].Start_xy();
			}
			i++;
		}
		m_Create_Clock = clock();
	}
}

int WordManager::Falling_Word(Interface UI, int& life)
{
	m_Word_Status = SAFE;
	int Word_Status;
	if (m_Item_Status == ALL_STOP)
		return m_Word_Status;
	if (clock() - m_Falling_Clock >= m_Falling_Speed)
	{
		for (int i = 0; i < m_Word_Max; i++)
		{
			if (m_Word_List[i].GetDisplay())
			{
				Word_Status = m_Word_List[i].Drop(m_Item_Status);
				if (Word_Status == DIE)
				{
					m_Word_Status = DIE;
					life--;
				}
				else if (Word_Status == BLIND)
				{
					UI.BoxDraw();
					UI.BoxText();
				}
			}
		}
		m_Falling_Clock = clock();
		return m_Word_Status;
	}
	return m_Word_Status;
}

bool WordManager::Check_Word(string answer, int& score)
{
	for (int i = 0; i < m_Word_Max; i++)
	{
		if (m_Word_List[i].GetDisplay())
		{
			if (m_Word_List[i].GetWord() == answer)
			{
				score += m_Word_List[i].GetWord().length() * 33;
				Active_Item(m_Word_List[i].Safe(), score); // 아이템 기능
				return true;
			}
		}
	}
	return false;
}

void WordManager::Active_Item(ITEM item, int& score)
{
	if (item == NON)
		return;
	m_Item_Status = item;
	switch (item)
	{
	case SPEED_UP:
		m_Falling_Speed -= INCREASE_FALLING_SPEED;
		break;
	case SPEED_DOWN:
		m_Falling_Speed += DECREASE_FALLING_SPEED;
		break;
	case ALL_STOP: // 변수활용해서 생성, 낙하 함수에서 적용
	case ALL_BLIND: // 동일
		break;
	case ALL_CLEAR:
		ReSet_Word(&score);
		m_Item_Status = NON;
		break;
	}
	m_Item_Clock = clock();
}

void WordManager::Active_Finigh()
{
	if (m_Item_Status == NON)
		return;
	if (clock() - m_Item_Clock >= ITEM_TIME)
	{
		if (m_Item_Status == SPEED_UP)
			m_Falling_Speed += INCREASE_FALLING_SPEED;
		else if (m_Item_Status == SPEED_DOWN)
			m_Falling_Speed -= DECREASE_FALLING_SPEED;
		m_Item_Status = NON;
	}
}

WordManager::~WordManager()
{
	delete[] m_Word_List;
}