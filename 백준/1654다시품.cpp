#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];

int main()
{
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> a[i];
	sort(a, a + K);
	long long start = 1;
	long long end = a[K - 1];
	long long mid,result;

	while (start <= end)
	{
		mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += a[i] / mid;
		}
		if (sum >= N)
		{
			result = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << result;
}