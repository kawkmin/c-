#include<iostream>
using namespace std;

int main()
{
	int n, x = 0;
	cin >> n;
	int a[1001];
	int dp[1001];
	int max, cnt;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		max = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + 1; //max가 dp[이전값]을 이용하여 나오는 거니까 dp가 맞다


		if (dp[i] > x)//최대값 구하기
			x = dp[i];
	}
	cout << x;
}
