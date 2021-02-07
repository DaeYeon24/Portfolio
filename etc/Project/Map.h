#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Character.h"

class Map
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
	MapDraw m_MapDrawManager;
	Character m_CharManager;
public:
	void MapDraw();
	void CharacterStart();
	Map();
	~Map();
};

