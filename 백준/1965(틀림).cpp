#include<iostream>

using namespace std;

int main()
{
	int n,box[1001],dp[1001],result=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> box[i];
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j <i; j++)
		{
			if (box[i] > box[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}
	cout << result;
}