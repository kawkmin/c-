#include <iostream>

using namespace std;

int main()
{
	int a[5],result=0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		result += a[i] * a[i];
	}
	int x = result % 10;
	cout << x;
}
