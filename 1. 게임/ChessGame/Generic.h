#pragma once
#include <Windows.h>
#include <cmath>	
#include "resource.h"
#include <vector>
#pragma comment(lib, "msimg32.lib")
using namespace std;

enum CHESSMANMODEL_NUMBER
{
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	PAWN,
	TOTAL
};

enum PROMOTIONMODEL
{
	NON,
	PROMOTION_QUEEN,
	PROMOTION_BISHOP,
	PROMOTION_KNIGHT,
	PROMOTION_ROOK
};

enum TEAM
{
	BLACK,
	WHITE
};