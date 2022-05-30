#include<iostream>

using namespace std;
int N, K;
long long int dp[201][201];

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= K; i++)
	{											//dp[3][30] = 3개로 30을 만들어야 하는 경우
		for (int j = 0; j <= N; j++)			//마지막에 더하는 수가 0이라면 2개로 30을 만드는 경우가 나올테고
		{										//마지막에 더하는 수가 1이라면 2개로 29를 만드는 경우가 나올테고
			for (int k = 0; k <= j; k++)		//마지막에 더하는 수가 2라면 2개로 28을 만드는 경우가 나옴
			{
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[K][N];
}