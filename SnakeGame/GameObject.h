#pragma once
#include "Vector2.h"
#include "Utility.h"

class GameObject
{
protected :
	Vector2 m_Position;
	wchar_t* m_Sprite;

public:
	GameObject(Vector2 pos, wchar_t* sprite);
	GameObject();
	~GameObject();
	
public:
	Vector2 Position();
	wchar_t* Sprite();

public:
	void Position(Vector2 pos);
	void Sprite(wchar_t* sprite);
};