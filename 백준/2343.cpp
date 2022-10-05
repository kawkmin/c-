#include<iostream>

using namespace std;
long long a[100001];

int main()
{
	long long N, M, sum = 0;
	cin >> N >> M;
	long long start = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += a[i];
		start = max(start, a[i]);
	}
	long long end = sum;
	while (start <= end)
	{
		long long cnt = 0;
		long long tempsum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
		{
			if (tempsum + a[i] > mid)
			{
				cnt++;
				tempsum = 0;
			}
			tempsum += a[i];
		}
		if (tempsum != 0) cnt++;
		if (cnt <= M)
		{
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	cout << start;
}
