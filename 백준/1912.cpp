#include <iostream>
#include<algorithm>
using namespace std;
int N, n[100001], dp[100001], index;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> n[i];
	dp[0] = n[0];
	for (int i = 1; i < N; i++)
	{
		if (dp[i - 1] > dp[i - 1] + n[i])				//if (dp[i - 1] + n[i] < n[i])		
			dp[i] = max(dp[i-1]+n[i],n[i]);		    	//		dp[i] = n[i];

		else if(dp[i-1]<0)
			dp[i] = n[i];
		
		else
			dp[i] = dp[i - 1] + n[i];
	}
	sort(dp, dp + N);
	cout << dp[N-1];
}
