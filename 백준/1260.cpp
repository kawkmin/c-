#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, V,c[1001],C[1001];
queue<int> q;
vector<int> v[10001];

void dfs(int V)
{
	if (c[V]) return;
	c[V] = true;
	cout << V << ' ';
	for (int i = 0; i < v[V].size(); i++)
	{
		int y = v[V][i];
		dfs(y);
	}
}

void bfs(int V)
{
	q.push(V);
	C[V] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!C[y])
			{
				q.push(y);
				C[y] = true;
			}
		}
	}
}

int main()
{
	int x, y;

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= M; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	
	dfs(V);
	cout << "\n";
	bfs(V);
}

