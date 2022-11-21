#include "Tile.h"

Tile::Tile(Vector2 pos, wchar_t* sprite, TILETYPE type) : GameObject(pos, sprite)
{
	this->m_TileType = type;
}

Tile::Tile() 
{

}

TILETYPE Tile::TileType()
{
	return m_TileType;
}

void Tile::TileType(TILETYPE type)
{
	m_TileType = type;
}