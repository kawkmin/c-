#include<iostream>

using namespace std;

long long a[10001];
long long K, N,x=1,M=0;

bool tru(long long n)
{
	long long count = 0;
	for (int i = 0; i < K; i++)
	{
		count += a[i] / n;
	}
	return (count >= N);
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i];
		if (a[i] > M)
			M = a[i];
	}
	long long start = 1,end=M;
	while (start<=end)
	{
		long long mid = (start + end) / 2;
		if (tru(mid))
		{
			x = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << x;
}
