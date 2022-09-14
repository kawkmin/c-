#include<iostream>
#include<cstring>
using namespace std;

int dp[2][1000001];
int a[2][1000001];

int dy(int y, int x)
{

	if (dp[y][x])
		return dp[y][x];
	int ay = 0;
	if (y == 1)
		ay = 0;
	else
		ay = 1;

	return dp[y][x] = max(dy(ay, x - 2), dy(ay, x - 1)) + a[y][x];
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));


		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		dp[0][0] = a[0][0];
		dp[1][0] = a[1][0];
		if (n > 1)
		{
			dp[1][1] = a[0][0] + a[1][1];
			dp[0][1] = a[0][1] + a[1][0];
		}
		int result = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 2; j < n; j++)
			{
				int x = dy(i, j);
				if (x > result)
					result = x;
			}
		}
		cout << result << "\n";
	}
}