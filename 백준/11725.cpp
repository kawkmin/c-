#include<iostream>
#include<vector>
using namespace std;

vector<int> v[1000001];
int a[1000001];
int ar[1000001];

void dfs(int x)
{
	a[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!a[v[x][i]])
		{
			ar[v[x][i]] = x;
			dfs(v[x][i]);
		}
	}
	
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
	{
		cout << ar[i] << "\n";
	}
}