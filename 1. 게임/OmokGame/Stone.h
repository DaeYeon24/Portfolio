#pragma once
#include "Basic.h"
#include "Draw.h"

class Stone
{
private:
	Draw* m_DrawManager;
	string m_strCursor;
	string m_strStone;
	string m_strName;
	Position m_XY; // Ŀ�� ��ǥ
	Restrict m_Limit; //������� �� ��ŭ �̵��� �� �ִ¤� �ø�
	Position* m_Record; // ���� �� ��ǥ
	int m_iDiagonal; //�¸�üũ�� �밢�� �˻� ����
	int m_iCount; // ���� ���� ����
	int m_iUndo;
public:
	static string strStone_1p;
	static string strCursor_1p;
	static string strStone_2p;
	static string strCursor_2p;
	static 	int iUndo;
	Stone(int Width, int Height, int playernumber, Draw* DrawManager);
	~Stone();
	void AllStoneDraw();
	void DrawStone(int x, int y);
	void Erase(Stone* opponent);
	bool Check(Position CursorPosition, bool DrawStatus = false);
	void RemoveCursor();
	int Move(Stone* opponent);
	void Undo();
	int WinCheck(int x, int y);
	void ChangeIconSet(int playernumber);
	static void ChangeIcon(string str, int CurOrStone, int playernumber)
	{
		if (playernumber == PLAYER_1P)
		{
			if (CurOrStone == CURSORICON)
				strCursor_1p = str;
			else if (CurOrStone == STONEICON)
				strStone_1p = str;
		}
		else if (playernumber == PLAYER_2P)
		{
			if (CurOrStone == CURSORICON)
				strCursor_2p = str;
			else if (CurOrStone == STONEICON)
				strStone_2p = str;
		}
	}
	inline int GetCount()
	{
		return m_iCount;
	}
	inline Position* GetRecord()
	{
		return m_Record;
	}
	inline string GetName()
	{
		return m_strName;
	}
	inline int GetUndo()
	{
		return m_iUndo;
	}
	inline string GetIcon()
	{
		return m_strStone;
	}
	static void ChangeUndo(int num)
	{
		iUndo = num;
	}
	inline void SetName(string str)
	{
		m_strName = str;
	}
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};