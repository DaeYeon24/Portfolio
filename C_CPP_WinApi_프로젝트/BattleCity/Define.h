#pragma once
#include <Windows.h>
#include "resource.h" //맵툴 다이얼로그
#include <crtdbg.h> //메모리 체크
#include <time.h>
#include <list>
#include <fstream> //파일 입출력
using namespace std;

#define DLG_WIDTH 33 //다이얼로그 너비, 높이
#define DLG_HEIGHT 25
#define FULL_WIDTH 1150 // 윈도우 너비
#define INGAME_WIDTH 950 // 인게임 너비
#define HEIGHT 990 // 창 높이
#define ROW 800.0f / 13.0f //유닛 가로, 세로
#define COL 800.0f / 15.0f
#define BLOCK_ROW 950.0f / 13.0f // 블럭 가로, 세로
#define BLOCK_COL 950.0f / 15.0f
#define CAMP_X 475 //캠프 블럭 좌표
#define CAMP_Y 920
#define MOVETIME 1000 // 무브 쿨타임
#define ID_DLG_GB1 0 //그룹박스
#define ID_DLG_GB2 1

enum MAIN_BUTTON
{
	ID_MAIN_B1,
	ID_MAIN_B2,
	ID_MAIN_B3
};

enum DLG_BUTTON
{
	ID_DLG_B1 = 1,
	ID_DLG_B2,
	ID_DLG_B3,
	ID_DLG_B4,
	ID_DLG_B5,
	ID_DLG_B6,
	ID_DLG_B7,
	ID_DLG_B8,
	ID_DLG_B9,
	ID_DLG_B10,
	ID_DLG_B11,
	ID_DLG_B12,
	ID_DLG_B13
};

enum GAME_STATE
{
	BEFOREGAME,
	LOADING,
	INGAME,
	GAMEOVER,
	GAMECLEAR
};

enum STAGE
{
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5
};

enum UNIT_STATE
{
	CREATE,
	ALIVE,
	STOP,
	DESTROY,
	DISAPPEAR
};

enum DIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	DIRECTION_TOTAL
};

enum MOVEMENT
{
	MOVEMENT1,
	MOVEMENT2,
	MOVEMENT_TOTAL
};

enum MAP_OBJECT
{
	LOAD,
	BREAKABLEWALL,
	UNBREAKABLEWALL,
	FOREST,
	RIVER,
	CREATEPOINT,
	CAMP
};

enum ITEM_TYPE
{
	TYPE_STOP,
	TYPE_BOOM,
	TYPE_LIFE,
	TYPE_SPEED,
	TYPE_POWER
};

enum MISSILE_LEVEL
{
	LOW,
	HIGH
};