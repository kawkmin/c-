#include <iostream>

using namespace std;

int N,RGB[1001][3];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> RGB[i][j];
	}
	int dp[1001];
	int c[1001];
	dp[0] = RGB[0][0];
	c[0] = 0;
	if (dp[0] > RGB[0][1])
	{
		dp[0] = RGB[0][1];
		c[0] = 1;
	}
	if (dp[0] > RGB[0][2])
	{
		dp[0] = RGB[0][2];
		c[0] = 2;
	}

	for (int i = 1; i <= N; i++)
	{
		int x=100000,tempj,tempj2;
		for (int j = 0; j < 3; j++)
		{
			if (j == c[i - 1])
				continue;

			if (x > dp[i - 1] + RGB[i][j])
			{
				x = dp[i - 1] + RGB[i][j];
				tempj = j;
			}
		}
		int yy = 10000;
		int xx=10000,tempc;
		if (i > 2)
		{
			int y = dp[i - 2];
			for (int j = 0; j < 3; j++)
			{
				if (j == c[i - 2])
					continue;
				if (xx > dp[i - 2] + RGB[i - 1][j])
				{
					xx = dp[i - 2] + RGB[i - 1][j];
					tempc = j;
				}
			}
			
			for (int j = 0; j < 3; j++)
			{
				if (j == tempc)
					continue;
				if (yy > xx + RGB[i][j])
				{
					yy = xx + RGB[i][j];
					tempj2 = j;
				}
			}
		}
		if (x < yy)
		{
			c[i] = tempj;
			dp[i] = x;
		}
		else
		{
			c[i-1] = tempc;
			c[i]=tempj2;
			dp[i] = yy;
		}
	}
	cout << dp[N];
}