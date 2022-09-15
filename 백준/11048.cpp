#include<iostream>

using namespace std;

int N, M;
int dp[1001][1001];
int a[1001][1001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> a[i][j];
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}
	cout<<dp[N][M];
}