#include <iostream>
#include<vector>

using namespace std;

int main()
{
	int M, N;
	vector<long long> dp(100001);
	dp[0] = 0;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
	{
		long long s;
		scanf("%lld", &s);
		dp[i] = dp[i - 1] + s;
	}
	for (int z = 0; z < N; z++)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		cout << dp[j] - dp[i - 1] << "\n";
	}
}