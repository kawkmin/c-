#include<iostream>
#include<vector>

using namespace std;

vector<int> a[1001];
int N, M, u, v,cut=0;
bool c[1001];

void dfs(int x)
{
	c[x] = true;
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if(!c[y]) dfs(y);
	}
}

void comp()
{
	for (int i = 1; i <= N; i++)
	{
		if (!c[i])
		{
			cut++;
			dfs(i);
		}
	}
	cout << cut;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u); //¾Æ............
	}
	for (int i = 1; i <= N; i++)
	{
		if (!c[i])
		{
			cut++;
			dfs(i);
		}
	}
	cout << cut;
	
}

