#pragma once
#include "FoodSpawner.h"
#include "GameMap.h"
#include "Snake.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class SnakeGame
{
private:
	GameMap* m_Map;
	Snake* m_Snake;
	FoodSpawner* m_FoodSpwaner;

public:
	SnakeGame(int width, int height, int maxTailSize);
	~SnakeGame();
	void Start();

private:
	void Update();
	void Input();

	void CheckFood();
	bool IsContinue();
};

