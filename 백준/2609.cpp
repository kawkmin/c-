#include<iostream>

using namespace std;

void max(int a, int b)
{
	int c = 1,result;
	while (c <= a || c <= b)
	{
		if (a % c == 0 && b % c == 0)
		{
			result = c;
		}
		c++;
	}
	cout << result<<"\n";
	result *= (a / result) * (b / result);
	cout << result;
}




int main()
{
	int x, y;
	cin >> x >> y;
	max(x, y);
}