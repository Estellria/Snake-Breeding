#include "GameMap.h"

GameMap::GameMap(int width, int height) 
{
	m_MapWidth = width;
	m_MapHeight = height;

	CreateMap();
	InitializeMap();
}


GameMap::~GameMap() 
{

}


void GameMap::CreateMap() 
{
	m_Board = new Tile *[m_MapHeight];

	for (int col = 0; col < m_MapHeight; ++col) 
	{
		m_Board[col] = new Tile[m_MapWidth];
	}
}


void GameMap::InitializeMap() 
{
	for (int col = 0; col < m_MapHeight; ++col)
	{
		for (int row = 0; row < m_MapWidth; ++row)
		{
			bool colOutLine = (col == 0 || col == m_MapHeight - 1);
			bool rowOutLine = (row == 0 || row == m_MapWidth - 1);
			Vector2 pos = { row, col };

			switch (colOutLine || rowOutLine)
			{
				case true:  m_Board[col][row] = { pos, (wchar_t*)L"бс", TILETYPE::WALL }; break;
				case false: m_Board[col][row] = { pos, (wchar_t*)L" ", TILETYPE::EMPTY }; break;
			}
		}
	}
}


void GameMap::DrawMap() 
{
	for (int col = 0; col < m_MapHeight; ++col) 
	{
		for (int row = 0; row < m_MapWidth; ++row) 
		{
			ScreenPrint(row, col, m_Board[col][row].Sprite());
		}
	}
}


Vector2 GameMap::MapSize()
{
	return { m_MapWidth, m_MapHeight };
}


void GameMap::ChangeTileType(Vector2 pos, TILETYPE type) 
{
	switch (type)
	{
		case EMPTY: m_Board[pos.y][pos.x] = Tile(pos, (wchar_t*)L"  ", EMPTY); break;
		case FOOD:  m_Board[pos.y][pos.x] = Tile(pos, (wchar_t*)L"б▌", FOOD);  break;
	}
}


bool GameMap::OutOfRange(Vector2 headPos)
{
	Vector2 mapSize = MapSize();

	bool outX = (headPos.x > mapSize.x - 1 || headPos.x < 0);
	bool outY = (headPos.y > mapSize.y - 1 || headPos.y < 0);

	return (outX || outY);
}


TILETYPE GameMap::TileType(Vector2 pos) 
{
	return m_Board[pos.y][pos.x].TileType();
}