#pragma once
#include <Windows.h>
#include "resource.h"
#include <time.h>
#include <crtdbg.h>
#pragma comment(lib, "msimg32.lib")
using namespace std;

#define WIDTH 900
#define HEIGHT 1000

enum STAGE
{
	EASY = 5,
	NORMAL = 10,
	HARD = 15
};

enum GAME_STATE
{
	CONTINUE,
	BOOM,
	CLEAR
};

enum BLOCK_STATE
{
	BLIND,
	OPEN,
	MARK
};

enum CURSER_INTERACTION
{
	CURSOR_MARK,
	CURSOR_SELECT
};