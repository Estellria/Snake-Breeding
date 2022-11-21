#pragma once
#include "GameObject.h"


enum TILETYPE 
{
	EMPTY,
	WALL,
	FOOD 
};


class Tile : public GameObject
{
private:
	TILETYPE m_TileType;

public:
	Tile(Vector2 pos, wchar_t* sprite, TILETYPE type);
	Tile();

public:
	void TileType(TILETYPE type);
	TILETYPE TileType();
};

