#include "FoodSpawner.h"

FoodSpawner::FoodSpawner(float coolTime, GameMap* mapData)
{
	m_LastCreateTime = 0;
	m_CreateCoolTime = coolTime;

	m_Timer = clock();
	m_MapData = mapData;
	m_FoodPosAry = new Vector2[10]{ 0 };
}


FoodSpawner::~FoodSpawner()
{
	delete m_FoodPosAry;
}


bool FoodSpawner::ExistFood(Vector2 pos)
{
	if (m_MapData->TileType(pos) == TILETYPE::FOOD)
	{
		m_MapData->ChangeTileType(pos, TILETYPE::EMPTY);
		return true;
	}
	return false;
}


void FoodSpawner::CreateFood()
{
	double currTime = (double)(clock() / CLOCKS_PER_SEC);
	double coolTime = m_LastCreateTime + m_CreateCoolTime;

	if (coolTime < currTime) 
	{
		m_LastCreateTime = currTime;
		
		int maxX = m_MapData->MapSize().x - 1;
		int maxY = m_MapData->MapSize().y - 1;

		Vector2 randomVec = Vector2::Random(1, maxX, 1, maxY);
		m_MapData->ChangeTileType(randomVec, TILETYPE::FOOD);
	}
}