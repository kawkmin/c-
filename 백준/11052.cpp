#include <iostream>

using namespace std;
int N,p[10001],dp[10001];

int main() 
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + p[j]);
	}
	cout << dp[N];
}