#include<iostream>
#define Max 5
using namespace std;

class Queue
{
public:
	int Start = -1, End = -1;
	int Data[Max];
	void enQueue();
	void deQueue();
};

void Queue::enQueue()
{
	if (End == Max - 1)
	{
		cout << "Full !!!" << endl;
		return;
	}
	End++;
	cout << "Input a Int Type Value : ";
	cin >> Data[End];
}

void Queue::deQueue()
{
	if (Start == End)
	{
		cout << "Empty !!!" << endl;
		return;
	}
	Start++;
	cout << "deQueue Data : " << Data[Start] << endl;
}

int main()
{
	Queue Q1;
	for (int i = 0; i < 6; i++)
		Q1.enQueue();
	cout << endl;
	for (int i = 0; i < 6; i++)
		Q1.deQueue();
	cout << endl;

	system("PAUSE");
	return 0;
}
