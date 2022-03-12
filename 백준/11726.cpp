#include<iostream> 

using namespace std;

long d[1001];

long dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2; 
	if (d[n] != 0) return d[n];
	return d[n]=(dp(n - 1) + dp(n - 2))%10007;
}

int main()
{
	int n;
	cin >> n;
	cout << dp(n)<<'\n';
}