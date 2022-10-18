#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> dp[11];

int main()
{
	int n, k;
	cin >> n >> k;
	dp[1].push_back("1");
	dp[2].push_back("1+1");
	dp[2].push_back("2");
	dp[3].push_back("1+1+1");
	dp[3].push_back("1+2");
	dp[3].push_back("2+1");
	dp[3].push_back("3");
	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			for (int k = 0; k < dp[i - j].size(); k++)
			{
				dp[i].push_back(dp[i - j][k] + "+" + to_string(j));
			}
		}
	}
	for (int i = 0; i < dp[n].size(); i++)
		sort(dp[n].begin(), dp[n].end());
	if (dp[n].size()<k)
	{
		cout << -1;
		return 0;
	}
	cout << dp[n][k-1];
}