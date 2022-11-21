#include "SnakeGame.h"
#include <conio.h>
#include <Windows.h>

SnakeGame::SnakeGame(int width, int height, int maxTailSize)
{
	m_Snake = new Snake(maxTailSize);
	m_Map = new GameMap(width, height);
	m_FoodSpwaner = new FoodSpawner(3, m_Map);
}


SnakeGame::~SnakeGame()
{
	delete m_Map;
	delete m_Snake;
	delete m_FoodSpwaner;
}


void SnakeGame::Start()
{
	ScreenInit();
	this->Update();

	Sleep(200);
	ScreenClear();
}


void SnakeGame::Update()
{
	while (true)
	{
		Vector2 mapSize = m_Map->MapSize();
		ScreenClear(mapSize.x, mapSize.y);
		m_FoodSpwaner->CreateFood();

		m_Map->DrawMap();
		m_Snake->DrawSnake();
		m_Snake->Move();

		if (IsContinue())
		{
			CheckFood();
			Input();

			ScreenFlipping();
			Sleep(5);
		}
		else break;
	}
}


void SnakeGame::Input()
{
	if (_kbhit() && _getch() == 224)
	{
		int key = _getch();
		Vector2 direction = Vector2::Zero();

		switch (key)
		{
			case UP:	direction = Vector2::Up();	  break;
			case DOWN:  direction = Vector2::Down();  break;
			case LEFT:  direction = Vector2::Left();  break;
			case RIGHT: direction = Vector2::Right(); break;
		}

		if ((m_Snake->Direction() + direction) != Vector2::Zero())
		{
			m_Snake->Direction(direction);
		}
	}
}


bool SnakeGame::IsContinue()
{
	if (m_Map->OutOfRange(m_Snake->HeadPosition()))
	{
		return false;
	}
	if (m_Snake->CrashBody())
	{
		return false;
	}
	return true;
}


void SnakeGame::CheckFood()
{
	Vector2 headPos = m_Snake->HeadPosition();

	if (m_FoodSpwaner->ExistFood(headPos))
	{
		m_Snake->CreateTail();
	}
}