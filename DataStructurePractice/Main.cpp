#include "DS_class.h"

int main(void)
{
	stack S1;
	queue Q1;
	circleQueue CQ1;
	LinkedList L1;

	cout << "STACK" << endl;
	for (int i = 5; i < 11; i++)
		S1.push(i);
	cout << endl;
	for (int i = 5; i < 11; i++)
		S1.pop();
	cout << endl << endl;

	cout << "QUEUE" << endl;
	for (int i = 15; i < 21; i++)
		Q1.enQueue(i);
	cout << endl;
	for (int i = 15; i < 21; i++)
		Q1.deQueue();
	cout << endl;
	for (int i = -5; i < 1; i++)
		Q1.enQueue(i);
	cout << endl;
	for (int i = -5; i < 1; i++)
		Q1.deQueue();
	cout << endl << endl;

	cout << "CIRCLEQUEUE" << endl;
	for (int i = 15; i < 21; i++)
		CQ1.enCircleQueue(i);
	cout << endl;
	for (int i = 15; i < 21; i++)
		CQ1.deCircleQueue();
	cout << endl;
	for (int i = -5; i < 1; i++)
		CQ1.enCircleQueue(i);
	cout << endl;
	for (int i = -5; i < 1; i++)
		CQ1.deCircleQueue();
	cout << endl << endl;

	cout << "LINKEDLIST" << endl;
	for (int i = 0; i < 6; i++)
		L1.pushBack(i);
	cout << endl;
	for (int i = 10; i < 16; i++)
		L1.pushFront(i);
	cout << endl;
	for (int i = 0; i < 13; i++)
		L1.popFront();
	cout << endl << endl;
}