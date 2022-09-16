#include<iostream>

using namespace std;

int dp[101][100001];

int main()
{
	int N, K,W[101],V[101];
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= W[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
}