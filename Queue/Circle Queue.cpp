#include <iostream>
#define Max 5
using namespace std;

class circleQueue
{
public:
	int start, end;
	int Data[Max];
	circleQueue(void)
	{
		start = end = (Max-1);          // need to initialize start, end = (Max-1)
	}
	void enQueue(int i);
	void deQueue();
};

void circleQueue::enQueue(int i)
{
	if (start == (end + 1) % Max)       // (xxx + 1) % Max is a key point of circle queue
	{
		cout << "Full!" << endl;
		return;
	}
	end = (end + 1) % Max;
	Data[end] = i;
	cout << "Eequeue : " << i << endl;
}

void circleQueue::deQueue()
{
	if (start == end)
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