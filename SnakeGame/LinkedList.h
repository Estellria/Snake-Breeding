#pragma once
#include "GameObject.h"

class LinkedList 
{
public:
	class Node
	{
	public:
		GameObject* data;
		Node* prev;
		Node* next;
	};

private:
	int m_Count;
	Node* m_Head;
	Node* m_Tail;


public:
	LinkedList();
	~LinkedList();

	void AddFirst(GameObject* data);


	void InsertList(int index, GameObject* data);


	void AddLast(GameObject* data);


	Node* SearchList(GameObject* data);


	void DeleteLast();


	void DeleteFirst();

public:
	int Count();

	Node* Head();

	Node* Tail();
};