#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include<crtdbg.h>
#include<Windows.h>
#include<time.h>
using namespace std;

#define HEIGHT 19
#define WIDTH 11
#define ELEVATOR_WIDTH 6
#define ELEVATOR_HEIGHT 6
#define POSITION_X (WIDTH-ELEVATOR_WIDTH-3)

#define DERECTION_UP 1
#define DERECTION_DOWN 2
#define DERECTION_WAIT 0
#define ELEVATOR_SPEED 300

#define TRUE 1
#define FALSE 0

struct People
{
	int Name;
	int Weight;
	struct People* Next;
};

struct Stack
{
	int MaxWeight;
	int MaxCount;
	int CurCount;
	int CurWeight;
	int y;
	int Derection;
	int OldClock;
	People* Head;
};