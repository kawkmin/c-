#include <iostream>
#include<algorithm>

using namespace std;

int N, n[500001], M, m[500001], cnt;

void find(int x)
{
	cnt = 0;
	int start = 0;
	int end = N;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (n[mid] == x)
		{
			int a = mid;
			cnt++;
			a++;
			while (n[a] == x)
			{
				cnt++;
				a++;
			}
			int b = mid;
			b--;
			while (n[b] == x)
			{
				cnt++;
				b--;
			}
			return;
		}
		if (n[mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
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
		find(m[i]);
		cout << cnt << " ";
	}
}
