#include<iostream>
using namespace std;

int fact(int n)
{
	int ans;
	if (n == 1)
		ans = 1;
	else if (n > 1)
		ans = n * fact(n - 1);
	return ans;
}

int main()
{
	int num;
	cout << "Please input an int data : ";
	cin >> num;
	cout << "Factorial of " << num << " is : " <<fact(num) << endl;
	return 0;
}
