#include<iostream>

using namespace std;

long long a[1000001];
long long N, M;

bool tru(long long n)
{
	long long sum=0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] > n)
		{
			sum += a[i] - n;
		}
	}
	return (sum >= M);
}

int main()
{
	long long max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
	}
	long long start = 1, end = max,x=0;

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
