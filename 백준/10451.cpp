#include<iostream>
#include<vector>

using namespace std;

vector<int> v[1001];
int a[1001];
int cnt = 0;
bool b = false;
void dfs(int x)
{
	a[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!a[v[x][i]])
		{
			dfs(v[x][i]);
		}
		else
		{
			b = true;
		}
	}
}

int main()
{
	int T,ax[1001];
	cin >> T;
	for (int ii = 0; ii < T; ii++)
	{
		int N;
		cnt=0;
		cin >> N;
		for (int i = 0; i <= N; i++)
		{
			a[i] = 0;
			v[i].clear();
		}
		for (int i = 0; i < N; i++)
		{
			cin >> ax[i];
		}
		for (int i = 0; i < N; i++)
		{
			v[ax[i]].push_back(ax[ax[i]-1]);
		}
		for (int i = 1; i <= N; i++)
		{
			if (!a[i])
			{
				dfs(i);
				if (b)
					cnt++;
				b = false;
			}
		}
		cout << cnt << "\n";
	}
}