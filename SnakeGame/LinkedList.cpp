#include "LinkedList.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	m_Count = 0;

	m_Head = new Node;
	m_Tail = new Node;

	m_Head->prev = NULL;
	m_Head->data = NULL;

	m_Tail->next = NULL;
	m_Tail->data = NULL;

	m_Head->next = m_Tail;
	m_Tail->prev = m_Head;
}


void LinkedList::AddFirst(GameObject* pos)
{
	Node* newNode = new Node;

	++m_Count;
	newNode->data = pos;

	newNode->next = m_Head->next;
	m_Head->next = newNode;

	newNode->prev = newNode->next->prev;
	newNode->next->prev = newNode;
}


void LinkedList::InsertList(int index, GameObject* data)
{
	if (m_Count == 0 || index >= m_Count)
	{
		return;
	}
	Node* newNode = new Node;
	newNode->data = data;

	Node* targetNode = m_Head;
	for (int i = 0; targetNode->next != m_Tail; ++i)
	{
		targetNode = targetNode->next;

		if (index == i)
		{
			newNode->prev = targetNode->prev;
			newNode->next = targetNode;
			targetNode->prev->next = newNode;

			++m_Count;
			return;
		}
	}
}


void LinkedList::AddLast(GameObject* data)
{
	Node* newNode = new Node;

	++m_Count;
	newNode->data = data;

	newNode->next = m_Tail;
	newNode->prev = m_Tail->prev;

	newNode->prev->next = newNode;
	m_Tail->prev = newNode;
}


LinkedList::Node* LinkedList::SearchList(GameObject* data)
{
	int index = 0;
	Node* tempNode = m_Head->next;

	while (tempNode != m_Tail)
	{
		++index;

		if (tempNode->data == data) 
		{
			return tempNode;
		}
		tempNode = tempNode->next;
	}
	return NULL;
}


void LinkedList::DeleteLast()
{
	Node* tempNode = m_Tail->prev;

	tempNode->prev->next = m_Tail;
	m_Tail->prev = tempNode->prev;
	delete tempNode;

	--m_Count;
}


void LinkedList::DeleteFirst()
{
	Node* tempNode = m_Head->next;

	tempNode->next->prev = m_Head;
	m_Head->next = tempNode->next;
	delete tempNode;

	--m_Count;
}


LinkedList::~LinkedList()
{
	Node* tempNode = m_Head->next;
	m_Count = 0;

	while (tempNode != m_Tail)
	{
		Node* currNode = tempNode;
		tempNode = tempNode->next;
		delete currNode;
	}
	delete m_Head;
	delete m_Tail;
}


int LinkedList::Count() 
{
	return m_Count;
}


LinkedList::Node* LinkedList::Head() 
{
	return m_Head;
}


LinkedList::Node* LinkedList::Tail() 
{
	return m_Tail;
}