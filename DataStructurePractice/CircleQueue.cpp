#include "DS_class.h"

void circleQueue::enCircleQueue(int i)
{
	if (Start == (Top + 1) % circleQueueMax)
	{
		cout << "Full!!!" << endl;
		return;
	}
	Top = (Top + 1) % circleQueueMax;
	Data[Top] = i;
	cout << "enCircleQueue : " << Data[Top] << endl;
	return;
}

void circleQueue::deCircleQueue(void)
{
	if (Start == Top)
	{
		cout << "Empty!!!" << endl;
		return;
	}
	Start = (Start + 1) % circleQueueMax;
	cout << "deCircleQueue : " << Data[Start] << endl;
	return;
}