#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<crtdbg.h>
#include<fstream>
#include<time.h>
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
#define WIDTH 40
#define HEIGHT 40
#define COOLTIME 500
#define FIRSTLINE 9
#define CANCEL 11

enum MAX
{
	MONSTER_MAX = 10,
	WEAPON_MAX = 40
};

enum WEAPON_TYPE
{
	BOW = 1,
	SWORD,
	WAND,
	SPEAR
};

enum FLAG
{
	PAUSE,
	DONE
};

enum KEY
{
	UP = 'w',
	DOWN = 's',
	ENTER = 13,
	SKILL = 'p'
};