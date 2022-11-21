#include "Snake.h"
#include "Utility.h"
#include <iostream>

Snake::Snake(int maxTailSize) 
{
	this->m_MaxTailSize = maxTailSize;
	this->m_TailCount = 1;

	m_MoveDir = Vector2::Right();

	m_SnakePos = new LinkedList;
	m_SnakePos->AddFirst(new GameObject({ 3,1 }, (wchar_t*)L"бс"));
	m_SnakePos->AddFirst(new GameObject({ 2,1,}, (wchar_t*)L"бр"));
}


void Snake::DrawSnake() 
{
	SetColor(10);
	LinkedList::Node* snake = m_SnakePos->Tail()->prev;

	while (snake != m_SnakePos->Head())
	{
		GameObject* obj = snake->data;
		Vector2 pos = obj->Position();

		ScreenPrint(pos.x, pos.y, obj->Sprite());
		snake = snake->prev;
	}
	SetColor(7);
}



void Snake::Direction(Vector2 moveDirection)
{
	m_MoveDir = moveDirection;
}


Vector2 Snake::Direction() 
{
	return m_MoveDir;
}


void Snake::Move() 
{
	LinkedList::Node* tempNode = m_SnakePos->Head()->next;

	for (int i = 0; i < m_TailCount; ++i)
	{
		GameObject* tempData = tempNode->data;
		tempNode = tempNode->next;

		tempData->Position(tempNode->data->Position());
	}

	GameObject* data = m_SnakePos->Tail()->prev->data;
	data->Position(data->Position() + m_MoveDir);
}


void Snake::CreateTail() 
{
	GameObject* data = m_SnakePos->Tail()->prev->data;
	Vector2 pos = data->Position() + m_MoveDir;
	data->Sprite((wchar_t*)L"бр");

	m_SnakePos->AddLast(new GameObject(pos, (wchar_t*)L"бс"));
	m_TailCount++;
}


Vector2 Snake::HeadPosition() 
{
	LinkedList::Node* tempNode = m_SnakePos->Tail()->prev;
	return tempNode->data->Position();
}


void Snake::HeadPosition(Vector2 pos) 
{
	LinkedList::Node* tempNode = m_SnakePos->Tail()->prev;
	tempNode->data->Position(pos);
}


bool Snake::CrashBody() 
{
	Vector2 headPos = HeadPosition();
	LinkedList::Node* tempNode = m_SnakePos->Tail()->prev;

	while (tempNode->prev != m_SnakePos->Head())
	{
		tempNode = tempNode->prev;

		if (tempNode->data->Position() == headPos) 
		{
			return true;
		}
	}
	return false;
}