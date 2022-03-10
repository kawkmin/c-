#include<iostream>

using namespace std;

int d[1001];

int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3; //d[2]일땐 3가지 방법이지만, 앞으로 2단위가 추가될 때마다는 2가지 경우 이므로 2*해야함 
	if (d[n] != 0) return d[n];
	return d[n] = (dp(n - 1) + 2*dp(n - 2)) % 10007;
}

int main()
{
	int n;
	cin >> n;
	cout<<dp(n);
}
