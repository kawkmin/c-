#include<iostream>

using namespace std;

long long d[91][2];

void dp(int x)
{
	for (int i = 3; i <= x; i++) 
	{
		d[i][0] = d[i - 1][1] + d[i - 1][0];
		d[i][1] = d[i - 1][0];
	}
}

int main()
{
	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = 0;
	int N;
	cin >> N;
	dp(N);
	long long result = d[N][0] + d[N][1];
	cout << result;
}