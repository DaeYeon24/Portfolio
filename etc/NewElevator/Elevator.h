#pragma once
#include "Çì´õ.h"

class Elevator
{
public:
	void Input(Stack* Elevator);
	void MenuDraw();
	void MoveElevator(Stack* Elevator);
	void DrawElevatorInfo(Stack Elevator);
	void DrawPeopleInfo(People* P, int y);
	void SetElevator(Stack* Elevator);
	void DrawElevator(Stack Elevator);
	void EraseElevator(Stack Elevator);
	void Pop(Stack* Elevator);
	void Push(Stack* Elevator);
	void DrawTower();
	void DrawPeople(int x, int y);
	void ErasePeople(int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};