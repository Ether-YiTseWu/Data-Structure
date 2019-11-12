#include <iostream>
#define Max 5
using namespace std;

class circleQueue
{
public:
	int start, top;
	int Data[Max];
	circleQueue(void)
	{
		start = top = (Max-1);      // need to initialize start, end = (Max-1)
	}
	void enQueue(int i);
	void deQueue();
};

void circleQueue::enQueue(int i)
{
	if (start == (top + 1) % Max)       // (xxx + 1) % Max is a key point of circle queue
	{
		cout << "Full!" << endl;
		return;
	}
	top = (top + 1) % Max;
	Data[top] = i;
	cout << "Eequeue : " << i << endl;
}

void circleQueue::deQueue()
{
	if (start == top)
	{
		cout << "empty!" << endl;
		return;
	}
	start = (start+1) % Max;
	cout << "Dequeue : " << Data[start] << endl;
}

void main()
{
	circleQueue Q1;

	for (int i = 0; i < 6; i++)
		Q1.enQueue(i);
	cout << endl;

	for (int i = 0; i < 6; i++)
		Q1.deQueue();
	cout << endl;

	for (int i = 5; i < 10; i++)
		Q1.enQueue(i);
	cout << endl;

	for (int i = 5; i < 10; i++)
		Q1.deQueue();
}
