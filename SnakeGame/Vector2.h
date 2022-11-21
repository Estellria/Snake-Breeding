#pragma once
#include <stdlib.h>

struct Vector2
{
public:
	int x;
	int y;

public:
	static Vector2 Zero() 
	{
		return { 0, 0 };
	}

	static Vector2 Up()
	{
		return { 0, -1 };
	}

	static Vector2 Down()
	{
		return { 0, 1 };
	}

	static Vector2 Left()
	{
		return { -1, 0 };
	}

	static Vector2 Right()
	{
		return { 1, 0 };
	}

	static Vector2 Random(int minX, int maxX, int minY, int maxY)
	{
		int x = (rand() % (maxX - minX)) + minX;
		int y = (rand() % (maxY - minY)) + minY;

		return { x, y };
	}

public:
	Vector2 operator+(Vector2 other)
	{
		return { x + other.x, y + other.y };
	}

	Vector2 operator-(Vector2& other)
	{
		return { x - other.x, y - other.y };
	}

	bool operator==(Vector2& other) 
	{
		return (x == other.x && y == other.y);
	}

	bool operator!=(Vector2 other) 
	{
		return (x != other.x || y != other.y);
	}
};

