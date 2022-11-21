#pragma once
#include "Tile.h"

class GameMap
{
private:
	int m_MapWidth;
	int m_MapHeight;
	Tile** m_Board;

public:
	GameMap(int width, int height);
	~GameMap();

	void DrawMap();

public:
	Vector2 MapSize();
	void ChangeTileType(Vector2 pos, TILETYPE type);
	bool OutOfRange(Vector2 snakePos);
	TILETYPE TileType(Vector2 pos);

private:
	void CreateMap();
	void InitializeMap();
};