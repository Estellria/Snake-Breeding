#include "GameObject.h"


GameObject::GameObject(Vector2 pos, wchar_t* sprite)
{
	m_Position = pos;
	m_Sprite = sprite;
}



GameObject::GameObject() 
{
	m_Position = { 0, 0 };
	m_Sprite = (wchar_t*)L"";
}



GameObject ::~GameObject() 
{

}

#pragma region Getter
Vector2 GameObject::Position() 
{
	return m_Position;
}


wchar_t* GameObject::Sprite() 
{
	return m_Sprite;
}
#pragma endregion

#pragma region Setter
void GameObject::Position(Vector2 pos) 
{
	m_Position = pos;
}


void GameObject::Sprite(wchar_t* sprite) 
{
	m_Sprite = sprite;
}
#pragma endregion