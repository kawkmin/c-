#include <iostream>
#include<algorithm>

using namespace std;

int N, n[500001], M, m[500001], cnt;

int low_bound(int x)
{
	int start = 0;
	int end = N;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (n[mid] >= x)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int up_bound(int x)
{
	int start = 0;
	int end = N;
	while (start < end)
	{
		int mid = (start + end) / 2;

		if (n[mid] <= x)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &m[i]);
	}
	sort(n, n + N);
	for (int i = 0; i < M; i++)
	{
		cnt = 0;
		int x=low_bound(m[i]);
		int y = up_bound(m[i]);
		for (int i = x; i <= y; i++)
			cnt++;
		cout << cnt << " ";
	}
}
