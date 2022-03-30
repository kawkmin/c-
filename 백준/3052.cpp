#include <iostream>

using namespace std;

int main()
{
	int a[43] = { 0, };
	int x;
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		x %= 42;
		if (a[x] == 0)
		{
			a[x] = 1;
			result++;
		}
	}
	cout << result;
	
}
