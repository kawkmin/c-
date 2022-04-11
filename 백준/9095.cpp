#include<iostream>

using namespace std;

int n,dp[11];

int dy(int x)
{
	if (!dp[x]) 
	{
		if (x == 0)
			return 0;
		else if (x == 1)
			return dp[x] = 1;
		else if (x == 2)
			return dp[x] = 2;
		else if (x == 3)
			return dp[x] = 4;
		else
		dp[x] = dy(x - 1) + dy(x - 2) + dy(x - 3);//x= 1+(x-1) ,2+(x-2),3+(x-3)
	}
	return dp[x];
}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		dy(n);
		cout << dp[n]<<'\n';
	}
}