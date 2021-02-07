#include "Draw.h"

Draw::Draw(int x, int y)
{
	m_iWidth = x;
	m_iHeight = y;
}

void Draw::BoardDraw(int Show)
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight + 5, m_iWidth * 2 + 1);
	system(buf);
	for (int y = 0; y < m_iHeight; y++)
	{
		if (y == 0)
		{
			cout << "��";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "��";
				else
					cout << "��";
			}
			cout << "��";
		}
		else if (y == m_iHeight - 1)
		{
			cout << "��";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "��";
				else
					cout << "��";
			}
			cout << "��";
		}
		else
		{
			if (Show == HIDE)
				cout << "��";
			else
				cout << "��";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "  ";
				else
					cout << "��";
			}
			if (Show == HIDE)
				cout << "��";
			else
			cout << "��";
		}
		cout << endl;
	}
	return;
}

void Draw::ReDraw(Position XY)
{
	if (XY.ix == 0 && XY.iy == 0)
		cout << "��";
	else if (XY.ix == 0 && XY.iy == m_iHeight - 1)
		cout << "��";
	else if (XY.ix == m_iWidth - 1 && XY.iy == 0)
		cout << "��";
	else if (XY.ix == m_iWidth - 1 && XY.iy == m_iHeight - 1)
		cout << "��";
	else if (XY.ix == 0)
		cout << "��";
	else if (XY.ix == m_iWidth - 1)
		cout << "��";
	else if (XY.iy == 0)
		cout << "��";
	else if (XY.iy == m_iHeight - 1)
		cout << "��";
	else
		cout << "��";
}

void Draw::BoardUnderDraw(string Name, int UndoCount, int turn)
{
	if (UndoCount == NULL && turn == NULL)
		BoardUnderText("Player Name : ", 1, Name);
	else
	{
		BoardUnderText("Turn : ");
		cout << turn;
		BoardUnderText("Player Name : ", 1, Name, "  ������ : ");
		cout << UndoCount;
	}
	BoardUnderText("====����Ű====", 2);
	BoardUnderText("�̵� : A, S, W, D\t������ : ENTER", 3);
	BoardUnderText("������ : N �ɼ� : P ���� : ESC", 4);
}

int Draw::Menu()
{
	int select;
	Text(" �� �� �� ��");
	Text("1. ���� ����", 2);
	Text("2. RePlay", 4);
	Text("3. ���� �ɼ�", 6);
	Text("4. ���� ����" , 8);
	Text("____________" , 10);
	gotoxy(m_iWidth / 2, (m_iHeight / 4) + 10);
	cin >> select;
	return select;
}

int Draw::SecondMenu()
{
	int select;
	BoardDraw(HIDE);
	Text(" �� �� �� ��");
	Text("1. �� ũ�� ����", 2);
	Text("2. Ŀ�� ����", 4);
	Text("3. �ٵϾ� ����", 6);
	Text("4. ������ Ƚ�� ����", 8);
	Text("5. ���ư���", 10);
	Text("____________", 12);
	gotoxy(m_iWidth / 2, (m_iHeight / 4) + 12); // �̰� ���� ����
	cin >> select;
	return select;
}

void Draw::Text(string str, int add)
{
	gotoxy((m_iWidth / 2) - (str.length() / 4), (m_iHeight / 4) + add);
	cout << str;
}

void Draw::BoardUnderText(string str1, int add, string str2, string str3)
{
	gotoxy((m_iWidth / 2) - ((str1.length() + str2.length() + str3.length()) / 4), m_iHeight + add);
	cout << str1 << str2 << str3;
}

Draw::~Draw()
{

}