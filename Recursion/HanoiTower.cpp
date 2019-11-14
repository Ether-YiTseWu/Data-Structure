#include <iostream>
#include <stdlib.h>
using namespace std;

void hannoi(int n, char a, char b, char c)
{
	if (n == 1)
    {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        return;
    }
    hannoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << c << endl;
    hannoi(n - 1, b, a, c);
}

int main()
{
	int n;
	cout << "Please input an int data : ";
	cin >> n;
	hannoi(n, 'A', 'B', 'C');

    system("pause");
	return 0;
}
