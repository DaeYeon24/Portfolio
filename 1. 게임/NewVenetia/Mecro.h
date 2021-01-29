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
#define WIDTH 70
#define HEIGHT 40
#define MAX 30
#define TOPFIFTEEN 15
#define PICK 0

enum TIME
{
	FIRST_CREATE_TIME = 1000,
	FIRST_FALLING_TIME = 500,
	PENALTY_TIME = 3000,
	ITEM_TIME = 3000,
	SCROLL_TIME = 500
};

enum STATUS
{
	SAFE,
	DIE,
	BLIND
};

enum UNDERLINE
{
	NAME = 1,
	SCORE = 32,
	LIFE = 56
};

enum KEY
{
	UP = 'w',
	DOWN = 's',
	ENTER = 13,
	BACKSPACE = 8
};

enum ITEM
{
	NON,
	SPEED_UP,
	SPEED_DOWN,
	ALL_STOP,
	ALL_BLIND,
	ALL_CLEAR
};

enum STAGE_SPEED
{
	STANDARD_FALLING_SPEED = 100,
	STANDARD_CREATE_SPEED = 500,
	STANDARD_MAX_UP = 4,
	INCREASE_FALLING_SPEED = 50,
	INCREASE_CREATE_SPEED = 100,
	DECREASE_FALLING_SPEED = 150
};