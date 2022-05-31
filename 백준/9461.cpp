#include<iostream>

using namespace std;

long long int dp[101];

void dy()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	int x = 3;
	for (int i = 8; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[x];
		x++;
	}
}

int main()
{
	int T,N;
	cin >> T;
	dy();
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout<<dp[N]<<"\n";
	}
}