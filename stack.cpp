#include <iostream>
#define size 10
using namespace std;

class stack
{
    public:
        int Top, Data[size]; // Just declare the member variable. Can't assign some values to these member variable.
        void push(int i);
        void pop();
        void listt();
    stack()
    {
        Top = -1;            // Use construct function to initialize the value of this variable.
    }
};

void stack::push(int i)
{
    if(Top >= size-1)        // Warning : because the code below it is "Top++", we must write ">= size-1".
    {
        cout << "Full" << endl;
        return ;
    }
    Top ++;
    Data[Top] = i;
}

void stack::pop()
{
    if(Top < 0)
    {
        cout << "Empty" << endl;
        return ;
    }
    cout << Data[Top] << endl;
    Top --;
}

int main()
{
    stack stEx;
    /*for (int i = 1 ; i<=11 ; i++)
        stEx.push(i);
    for (int i = 1 ; i<=11 ; i++)
        stEx.pop();*/
    int i;
    for (i = 1 ; i<12 ; i++)
        stEx.push(i);
    while(--i)
        stEx.pop();

    return 0;
}
