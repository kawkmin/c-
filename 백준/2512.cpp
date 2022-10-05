#include<iostream>
#include<algorithm>
using namespace std;
int N, a[10001];
int T;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cin >> T;
	sort(a, a + N);
	int start = 0;
	int end = a[N-1];
	int result, sum = 0;
	while (start <= end)
	{
		sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
			sum += min(a[i], mid);
		if (T >= sum)
		{
			result = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << result;
}