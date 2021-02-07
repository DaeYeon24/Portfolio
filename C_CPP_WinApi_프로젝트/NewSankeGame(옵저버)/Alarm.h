#pragma once
#include "Snake.h"

class Alarm
{
	string m_name;
	Snake* m_player;
protected:
	bool m_isAppear;
public:
	Alarm(string name) : m_name(name) {}
	void SetPlayer(Snake* player);
	void RemovePlayer();
	void Notification();
};

class Enemy : public Alarm, public Snake
{
public:
	Enemy() : Alarm("µ¶»ç") 
	{
		m_isAppear = false;
	}
	bool IsAppear();
	void SpawnEnemy();
	void RemoveEnemy();
	void AutoInput();
	void DrawSnake(int x, int y);
	int Move(Block* block, Enemy* enemy = NULL);
	void AUTO(Block* block);
	void EraseTail(list<LIST_BODY>::iterator CurPosition);
};