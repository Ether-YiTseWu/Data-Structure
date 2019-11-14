#include<iostream>
using namespace std;

#define stackMax 5
#define queueMax 5
#define circleQueueMax 5

class stack
{
public:
	int Top, Data[stackMax];
	stack(void)
	{
		Top = -1;
	}
	void push(int i);
	void pop(void);
};

class queue
{
public:
	int Top, Start, Data[queueMax];
	queue(void)
	{
		Top = Start = -1;
	}
	void enQueue(int i);
	void deQueue(void);
};

class circleQueue
{
public:
	int Top, Start, Data[circleQueueMax];
	circleQueue(void)
	{
		Top = Start = circleQueueMax -1;
	}
	void enCircleQueue(int i);
	void deCircleQueue(void);
};

class Node
{
public:
	int Data;
	Node* next;
	Node(int i)
	{
		Data = i;
		next = NULL;
	}
};
class LinkedList
{
public:
	Node* Head = new Node(1);
	void pushFront(int i);
	void pushBack(int i);
	void popFront(void);
};