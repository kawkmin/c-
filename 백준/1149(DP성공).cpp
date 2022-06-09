#include <iostream>

using namespace std;

int N,cost[3];
int dp[1001][3];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}