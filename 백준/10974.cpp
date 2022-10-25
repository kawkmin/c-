#include<iostream>
#include<vector>
using namespace std;
int n;
int visit[9];
vector<int> v;

void dfs(int x,int dep)
{
	v.push_back(x);
	visit[x] = 1;
	if (dep == n)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs(i, dep + 1);
			visit[i] = 0;
			v.pop_back();
		}
	}
}

int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 1);
		for (int j = 1; j < 9; j++)
			visit[j] = 0;
		for (int j = 0; j < v.size(); j++)
			v.pop_back();
	}
}