#include<iostream>

using namespace std;

int main()
{
	int N, K,a[11],count=0;
	cin >> N >> K;
	for(int i=1;i<=N;i++)
	{
		cin >> a[i];
	}
	for (int i = N; i >= 1; i--)
	{
		count += K / a[i];
		K %= a[i];
	}
	cout << count;
}
