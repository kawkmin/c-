#include<iostream>

using namespace std;

int cnt = 0;

void dec(int x)
{
	bool b = true;
	if (x == 0 || x == 1)
		return;
	if (x == 2) 
	{
		cnt++;
		return;
	}
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			b = false;
		}
	}
	if (b)
		cnt++;

}

int main()
{
	int N;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		dec(a);
	}
	cout << cnt;
}