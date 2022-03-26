#include<iostream>
#include<vector>

using namespace std;
int color[20001];
bool b = true;
int K, V, E, x, y;
vector<int> a[20001];

void dfs(int x)
{
	if (!color[x]) {
		color[x] = 1;
	}
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (!color[y])
			{
				if (color[x] == 1)
					color[y] = 2;
				else if (color[x] == 2)
					color[y] = 1;
				dfs(y);
			}
		if (color[y] == color[x]) 
		{
			b = false;
			return;
		}
	}
}

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		for (int k = 1; k <= V; k++)
		{
			color[k] = false;
			a[k].clear();
		}
		for (int j = 0; j < E; j++)
		{
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int k = 0; k < V; k++) {
			if (!color[k]) {
				dfs(k);
			}
		}
		if (b)
			cout << "YES\n";
		else
			cout << "NO\n";
		b = true;
	}
}