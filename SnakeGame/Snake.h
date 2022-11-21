#pragma once
#include "LinkedList.h"
#include "Vector2.h"
#include "Utility.h"

//녹색으로 출력
class Snake
{
private:
	int m_TailCount;
	int m_MaxTailSize;

public:
	Vector2 m_MoveDir;
	LinkedList* m_SnakePos;

public:
	Snake(int maxTailSize);

	void CreateTail();
	void DrawSnake();
	void Move();
	bool CrashBody();

public:
	void Direction(Vector2 dir);
	Vector2 Direction();
	void HeadPosition(Vector2 pos);
	Vector2 HeadPosition();
};

