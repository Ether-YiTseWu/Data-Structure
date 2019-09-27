# include<iostream>
# define SIZE 10
using namespace std;

template <class T>
class stack
{
public:
	T Data[SIZE];
	T Top;
	void Push( T );
	void Pop();

	stack( T ini)
	{
		Top = ini;
	}
};

template<class T>
void stack<T>::Push(T i)
{
	if (Top >= (SIZE - 1))
	{
		cout << "Full" << endl;
		return;
	}
	Top++;
	Data[Top] = i;
	cout << "Push : " << i << endl;
}

template<class T>
void stack<T>::Pop()
{
	if (Top < 0)
	{
		cout << "Empty" << endl;
		return;
	}
	cout << "Pop : " << Data[Top] << endl;
	Top--;
}

int main()
{
	stack<int> st1(-1);
	stack<char> st2(-1);
	int i, j;

	for (i = 0; i < 11; i++)
		st1.Push(i);
	while (i--)
		st1.Pop();

	cout << endl;
	cout << endl;
	cout << endl;

	for (j = 0; j < 11; j++)
		st2.Push('A'+ j);
	while (j--)
		st2.Pop();

	system("pause");
	return 0;
}
