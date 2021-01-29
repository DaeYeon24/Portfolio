#pragma once
#include <Windows.h>
#include <time.h>
#include <crtdbg.h>
#include <vector>
#pragma comment(lib, "msimg32.lib")
using namespace std;

#define UPDATE_TIME 200
#define WIDTH 1200
#define HEIGHT 800
#define START_X 350.0f
#define START_Y 542.0f
#define JUMP_X 150.0f
#define JUMP_Y 550.0f

enum STATE
{
	IDLE,
	RUN,
	BACKSTEP,
	JUMP,
	SHOCK,
	DIE,
	FINISH
};

enum PROGRESS
{
	FORWARD,
	BACKWARD
};

enum TRAPTYPE
{
	HURDLE,
	RING
};