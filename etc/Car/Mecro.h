#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX 10
#define CREATE 5000

enum LINE_FLOOR
{
	START_LINE = 5,
	END_LINE = 95,
	FOURTH_FLOOR = 0,
	THIRD_FLOOR = 5,
	SECOND_FLOOR = 10,
	FIRST_FLOOR = 15
};

enum SPEED
{
	FAST = 100,
	SLOW = 500
};

enum KEY
{
	ESC = 27,
	SPACEBAR = 32
};