#include <iostream>

using namespace std;

int main() 
{
	int a[10],max=0,x;
	for (int i = 1; i < 10; i++)
	{
		cin >> a[i];
    }
	for (int i = 1; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			x = i;
		}
	}
	cout << max << "\n" << x;
	
}
