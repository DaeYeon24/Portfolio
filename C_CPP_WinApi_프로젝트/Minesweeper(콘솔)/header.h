#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>
#include <crtdbg.h>
using namespace std;

//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////


#define MINE_BLOCK "※"
#define UNKNOWN_BLOCK "■"
#define EMPTY_BLOCK "□"
#define CURSOR "⊙"
#define MARK "♣"
#define AROUND_1 "①"
#define AROUND_2 "②"
#define AROUND_3 "③"
#define AROUND_4 "④"
#define AROUND_5 "⑤"
#define AROUND_6 "⑥"
#define AROUND_7 "⑦"
#define AROUND_8 "⑧"


enum KEY
{
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd',
	SELECT = 13,
	MARKING = 'm',
	ESC = 27,
};

enum STEP
{
	EXIT,
	CONTINUE,
	BOOM
};

enum CURSER_INTERACTION
{
	CURSOR_ERASE,
	CURSOR_MARK,
	CURSOR_SELECT
};