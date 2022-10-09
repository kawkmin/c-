#include <iostream>

using namespace std;
int a[2][100001];
int dp[2][100001];

int main()
{
	int T;
	cin >> T;
	for (int t= 0; t < T; t++)
	{
		fill(a[0], a[0] + 100001,0);
		fill(a[1], a[1] + 100001, 0);
		fill(dp[0], dp[0] + 100001, 0);
		fill(dp[1], dp[1] + 100001, 0);
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		dp[0][0] = a[0][0];
		dp[1][0] = a[1][0];
		dp[0][1] = a[0][1]+a[1][0];
		dp[1][1] = a[1][1]+a[0][0];
		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + a[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + a[1][i];
		}
		int result = max(dp[0][n - 1], dp[1][n - 1]);
		cout << result<<"\n";
	}
}