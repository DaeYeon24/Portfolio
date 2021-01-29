#pragma once
#include "Word.h"

class WordManager
{
private:
	Word* m_Word_List; // 단어 전체 목록
	ITEM m_Item_Status;
	int m_Item_Clock;
	int m_Word_Max;
	int m_Create_Clock;
	int m_Create_Speed;
	int m_Create_Max;
	int m_Falling_Clock;
	int m_Falling_Speed;
	int m_Falling_Count;
	int m_Stage_Level;
	int m_Word_Status;
public:
	WordManager();
	~WordManager();
	void Load();
	void Create_Word();
	int Falling_Word(Interface UI, int& life);
	bool Check_Word(string answer, int& score);
	void Stage_Up();
	void ReSet_Word(int* score = NULL);
	void ReSet_Stage();
	void Active_Item(ITEM item, int& score);
	void Active_Finigh();
	inline int GetStageLv()
	{
		return m_Stage_Level;
	}
};

