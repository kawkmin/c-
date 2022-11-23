#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M, cnt, ans;
int visit[21];

void dfs(vector<int> v[], int x, int cn)
{
	ans = max(cn, ans);
	for (int i = 0;i < v[x].size();i++)
	{
		if (visit[v[x][i]] == 0)
		{
			visit[v[x][i]] = 1;
			dfs(v, v[x][i], cn + 1);
			visit[v[x][i]] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1;t <= T;t++)
	{
		cin >> N >> M;
		cnt = 0;
		ans = 1;
		vector<int> v[21];
		int MAX = 0;
		for (int i = 0;i < M;i++)
		{
			int x, y;
			cin >> x >> y;
			MAX = max(MAX, max(x, y));
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1;i <= MAX;i++)
		{
			memset(visit, 0, sizeof(visit));
			cnt = 0;
			visit[i] = 1;
			dfs(v, i, 1);
			ans = max(cnt, ans);
		}
		cout << "#" << t << " " << ans << "\n";
	}
}