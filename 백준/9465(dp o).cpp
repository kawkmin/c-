#include <iostream>
#include<vector>

using namespace std;

int  N, n[2][100001],dp[2][100001];
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> n[0][i];
		for (int i = 0; i < N; i++)
			cin >> n[1][i];
		dp[0][0] = n[0][0];
		dp[1][0] = n[1][0];
		dp[0][1] = n[0][1] + dp[1][0];
		dp[1][1] = n[1][1] + dp[0][0];
		for (int i = 2; i < N; i++)
		{
			dp[0][i] = n[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = n[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		
		}			
		if (dp[0][N-1] > dp[1][N-1])
			cout << dp[0][N - 1] << "\n";
		else
			cout << dp[1][N - 1] << "\n";
	}
}
