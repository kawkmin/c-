#include<iostream>
#define mux 1000000000

using namespace std;

int dp[101][10] = { 0, };

void cal(int n)
{
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i - 1 == 0)
				continue;
			if (j - 1 != -1)
				dp[i][j] += dp[i - 1][j - 1]%mux;
			if (j + 1 != 10)
				dp[i][j] += dp[i - 1][j + 1]%mux;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	cal(N);
	long long sum=0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[N][i];
		sum %= mux;
	}
	cout << sum;
}