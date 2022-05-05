#include<iostream>

using namespace std;

int main()
{
	int A[1001],N,dp[1001],x=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[i])
			{
				if (dp[j] > max)
					max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (x < dp[i])
			x = dp[i];
	}
	cout << x;
}