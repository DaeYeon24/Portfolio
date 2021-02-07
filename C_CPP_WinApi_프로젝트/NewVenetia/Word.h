#pragma once
#include "Interface.h"

class Word
{
protected:
	Interface m_Interface;
	ITEM m_Item;
	string m_Word;
	int m_X;
	int m_Y;
	bool m_Display;
public:
	Word();
	~Word();
	void Start_xy();
	void Random_Item();
	void Draw(ITEM item = NON);
	int Drop(ITEM item);
	ITEM Safe();
	int Die();
	inline void SetWord(string str)
	{
		m_Word = str;
	}
	inline string GetWord()
	{
		return m_Word;
	}
	inline bool GetDisplay()
	{
		return m_Display;
	}
};

