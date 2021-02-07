#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define HIDE 5
#define DONE 1

enum PROGRESS
{
	EXIT,
	ING,
	PAUSE,
	RETURN,
	WIN
};

enum ICON
{
	CURSORICON,
	STONEICON
};

enum PLAYER
{
	PLAYER_1P = 1,
	PLAYER_2P
};

enum KEY
{
	LEFT = 'a',
	RIGHT = 'd',
	UP = 'w',
	DOWN = 's',
	UNDO = 'n',
	OPTION = 'p',
	DROP = 13,
	ESC = 27
};

struct Position
{
	int ix;
	int iy;
	Position() {}
	Position(int x, int y)
	{
		ix = x;
		iy = y;
	}
};

struct Restrict
{
	int iLeft;
	int iTop;
	int iRight;
	int iBottom;
};