#pragma once
#include "GameMap.h"
#include <iostream>
#include <time.h>

class FoodSpawner
{
private:
	double m_CreateCoolTime;
	double m_LastCreateTime;

	Vector2* m_FoodPosAry;
	GameMap* m_MapData;
	clock_t m_Timer;

public:
	FoodSpawner(float coolTime, GameMap* mapData);
	~FoodSpawner();

	bool ExistFood(Vector2 pos);
	void CreateFood();
};