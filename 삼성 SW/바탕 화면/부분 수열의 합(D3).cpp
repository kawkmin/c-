#include<iostream>
#include<string>
using namespace std;
int N, K, arr[21], cnt = 0;

void dfs(int n, int k)
{
	if (k == K)
	{
		cnt++;
	}
	if (n == N - 1) return;
	dfs(n + 1, k + arr[n]);
	dfs(n + 1, k);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1;t <= T;t++)
	{
		cin >> N >> K;

		for (int i = 0;i < N;i++)
		{
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << "#" << t << " " << cnt << "\n";
	}
}