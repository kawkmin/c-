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
		dp[i] = max + 1; //max�� dp[������]�� �̿��Ͽ� ������ �Ŵϱ� dp�� �´�


		if (dp[i] > x)//�ִ밪 ���ϱ�
			x = dp[i];
	}
	cout << x;
}
