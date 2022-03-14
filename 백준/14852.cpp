#include<iostream>

using namespace std;

long long int d[10000001][2];

long long int dp(int n)
{
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= n; i++)
	{
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % 1000000007;
		d[i][0] = (3 * d[i - 2][0] + 2*d[i - 1][0] + 2 * d[i][1]) % 1000000007;
	}
	return d[n][0];
}

int main()
{
	int n;
	cin >> n;
	cout << dp(n);
}





// 시간 초과 for문으로 시간복잡도 O(N^2) 되어서 
//int d[1000001];
//
//long long int dp(int d[],int n)
//{
//	long long int result;
//	if (n == 0)return 1;
//	if (n == 1)return 2;
//	if (n == 2)return 7;
//	if (d[n] != 0)return d[n];
//	result = 2 * dp(d,n - 1) + 3 * dp(d,n - 2);
//	for (int i = 3; i <= n; i++)
//	{
//		result +=( 2 * dp(d,n - i)) % 10000007;
//	}
//	return d[n] = result%10000007;
//}
//
//int main()		
//{
//	int n;
//	cin >> n;
//	cout << dp(d,n);
//}