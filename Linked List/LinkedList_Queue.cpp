# include<iostream>
using namespace std;

class Node
{
public:
	int Data;
	Node* next;
	Node(int d)
	{
		Data = d;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* Head = new Node(1);

	void Push_front(int);
	void enQueue(int);
	void deQueue();
};

void LinkedList::Push_front(int d)
{
	cout << "Push Front :" << d << endl;
	Node* newNode = new Node(d);
	if (Head->next == NULL)
	{
		Head->next = newNode;
		return;
	}
	newNode->next = Head->next;
	Head->next = newNode;
}
void LinkedList::enQueue(int d)
{
	Node* newNode = new Node(d);
	Node* lastNode = new Node(d);
	cout << "EnQueue Data : " << d << endl;
	if (Head->next == NULL)
	{
		Head->next = newNode;
		return;
	}
	lastNode = Head->next;
	while (lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = newNode;
}
void LinkedList::deQueue()
{
	if (Head->next == NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	Node* tempNode = new Node(1);
	tempNode = Head->next;
	cout << "DeQueue Data : " << tempNode->Data << endl;
	Head->next = tempNode->next;
	delete tempNode;
}

int main()
{
	LinkedList L1;

	for (int i = 0; i <= 10; i++)
		L1.enQueue(i);
	cout << endl;
	for (int i = 0; i <= 11; i++)
		L1.deQueue();

	system("PAUSE");
	return 0;
}