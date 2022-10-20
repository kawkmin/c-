#include<iostream>

using namespace std;
int arr[1025][1025],dp[1025][1025];

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= N; i++)
	{
		dp[i][1] = arr[i][1] + dp[i - 1][1];
		dp[1][i] = arr[1][i] + dp[1][i - 1];
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (int t = 0; t < M; t++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]<<"\n";
	}
}