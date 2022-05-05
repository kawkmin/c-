#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, A[1001],x=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	int dp[1001] = { 0, };
	for (int i = 0; i < N; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + A[i];
	}
	cout << dp[N-1];
}