#include "DS_class.h"

void queue::enQueue(int i)
{
	if (Top == queueMax - 1)
	{
		cout << "Full!!!" << endl;
		return;
	}
	Top++;
	Data[Top] = i;
	cout << "enQueue : " << Data[Top] << endl;
	return;
}

void queue::deQueue(void)
{
	if (Start == Top)
	{
		cout << "Empty!!!" << endl;
		return;
	}
	Start++;
	cout << "pop : " << Data[Start] << endl;
	return;
}