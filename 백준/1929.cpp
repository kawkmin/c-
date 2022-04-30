#include<iostream>
#include<cmath>
using namespace std;


bool dec(int x)
{
	if (x == 0 || x == 1)
		return false;
	int ax = (int)sqrt(x);
	for (int i = 2; i <= ax; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N,M;
	cin >> N>>M;
	for (int i = N; i <=M; i++)
	{
		if (dec(i))
			cout << i << "\n";
	}
	
}