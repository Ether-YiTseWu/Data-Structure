#include <iostream>
#define size 10
using namespace std;

class stack
{
    public:
        int Top, Data[size]; // Just declare the member variable. Can't assign some values to these member variables.
        void push(int i);
        void pop();
        void topData();
        void getSize();
    stack()
    {
        Top = -1;            // Use construct function to initialize the value of this member variable.
    }
};

void stack::push(int i)
{
    if(Top >= size-1)        // Warning : because the code below this line is "Top++", we must write ">= size-1".
    {
        cout << "Full" << endl;
        return ;
    }
    Top ++;
    Data[Top] = i;
    cout << "Push : " << i << endl;
}

void stack::pop()
{
    if(Top < 0)
    {
        cout << "Empty" << endl;
        return ;
    }
    cout << "Pop : " <<  Data[Top] << endl;
    Top --;
}

void stack::topData()
{
    cout << "the value of Top Data is : "<< Data[Top] << endl;
}

void stack::getSize()
{
    cout << "the size of Data is : " << Top+1 << endl;
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
