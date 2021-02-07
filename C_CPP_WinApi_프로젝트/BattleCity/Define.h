#pragma once
#include <Windows.h>
#include "resource.h" //���� ���̾�α�
#include <crtdbg.h> //�޸� üũ
#include <time.h>
#include <list>
#include <fstream> //���� �����
using namespace std;

#define DLG_WIDTH 33 //���̾�α� �ʺ�, ����
#define DLG_HEIGHT 25
#define FULL_WIDTH 1150 // ������ �ʺ�
#define INGAME_WIDTH 950 // �ΰ��� �ʺ�
#define HEIGHT 990 // â ����
#define ROW 800.0f / 13.0f //���� ����, ����
#define COL 800.0f / 15.0f
#define BLOCK_ROW 950.0f / 13.0f // �� ����, ����
#define BLOCK_COL 950.0f / 15.0f
#define CAMP_X 475 //ķ�� �� ��ǥ
#define CAMP_Y 920
#define MOVETIME 1000 // ���� ��Ÿ��
#define ID_DLG_GB1 0 //�׷�ڽ�
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