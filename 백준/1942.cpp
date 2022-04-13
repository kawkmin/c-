#include<iostream>

using namespace std;

int main()
{
	int x, y,sum=0;
	cin >> x >> y;
	while (x != 0)
	{
		if (x - 1 == 2)
			sum += 28;
		else if (x - 1 == 1 || x - 1 == 3 || x - 1 == 5 || x - 1 == 7 || x - 1 == 8 || x - 1 == 10)
		{
			sum += 31;
		}
		else if (x - 1 == 4 || x - 1 == 6 || x - 1 == 9 || x - 1 == 11)
		{
			sum += 30;
		}
		x--;
	}
	sum += y;
	sum %= 7;
	if (sum == 1)
	{
		cout << "MON";
	}
	else if (sum == 2)
	{
		cout << "TUE";
	}
	else if (sum == 3)
	{
		cout << "WED";
	}
	else if (sum == 4)
	{
		cout << "THU";
	}
	else if (sum == 5)
	{
		cout << "FRI";
	}
	else if (sum == 6)
	{
		cout << "SAT";
	}
	else if (sum == 0)
	{
		cout << "SUN";
	}

}