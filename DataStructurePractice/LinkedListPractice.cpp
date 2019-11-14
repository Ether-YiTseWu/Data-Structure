#include "DS_class.h"

void LinkedList::pushFront(int i)
{
	Node* newNode = new Node(i);
	cout << "pushFront : " << i << endl;
	if (Head->next == NULL)
	{
		Head->next = newNode;
		return;
	}
	newNode->next = Head->next;
	Head->next = newNode;
	return;
}

void LinkedList::pushBack(int i)
{
	Node* newNode = new Node(i);
	cout << "pushBack : " << i << endl;
	if (Head->next == NULL)
	{
		Head->next = newNode;
		return;
	}
	Node* lastNode = new Node(i);
	lastNode = Head;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
	return;
}

void LinkedList::popFront(void)
{
	if (Head->next == NULL)
	{
		cout << "Empty!!!" << endl;
		return;
	}
	Node* tempNode = new Node(1);
	tempNode = Head->next;
	cout << "popFront : " << tempNode->Data << endl;
	Head->next = tempNode->next;
	delete tempNode;
}