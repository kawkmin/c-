#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long X, Y;
	cin >> X >> Y;
	long long Z = (100 * Y) / X;
	long long start = 1;
	long long end = X;
	bool b = false;
	long long mid;
	while (start <= end)
	{
		long long x = X, y = Y;
		mid = (start + end) / 2;
		x += mid;
		y += mid;
		long long z = (y * 100) / x;
		if (z > Z)
		{
			b = true;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	if (!b)
		cout << -1;
	else
		cout << start;
}
