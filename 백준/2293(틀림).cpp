#include<iostream>
using namespace std;

int n, k,a[101],dp[10001];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= k; j++)
			dp[j] += dp[j - a[i]];
	}// 5원을 쓸 수 있으면 기존 6원을 만들 수 있는 수 + 1원을 만들 수 있었던 수(5+1은 6 이므로)
	cout << dp[k];
}