#include<iostream>

using namespace std;

int d[1001][10] = { 0, };
long long cnt = 0;
int N;

void dp(int x)
{
	for (int i = 1; i <= N; i++)
	{
		d[i][0] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				continue;
			}
			d[i][j] = d[i - 1][j] + d[i][j - 1];
			d[i][j] %= 10007;
		}
	}
}

int main()
{
	cin >> N;
	dp(N);
	for (int i = 0; i < 10; i++)
	{
		cnt += d[N][i];
		cnt %= 10007;
	}
	cout << cnt;
}