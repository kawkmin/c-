#include <iostream>

using namespace std;
int rgb[3][1001];
int dp[3][1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> rgb[j][i];
	dp[0][0] = rgb[0][0];
	dp[1][0] = rgb[1][0];
	dp[2][0] = rgb[2][0];
	for (int i = 1; i < N; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1])+rgb[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + rgb[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];
	}
	
	cout << min(min(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]);
}