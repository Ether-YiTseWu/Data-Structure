#include "DS_class.h"

void stack::push(int i)
{
	if (Top == stackMax - 1)
	{
		cout << "Full!!!" << endl;
		return;
	}
	Top++;
	Data[Top] = i;
	cout << "push : " << Data[Top] << endl;
	return;
}

void stack::pop(void)
{
	if (Top == -1)
	{
		cout << "Empty!!!" << endl;
		return;
	}
	cout << "pop : " << Data[Top] << endl;
	Top--;
	return;
}