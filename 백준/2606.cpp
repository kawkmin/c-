#include<iostream>
#include<vector>

using namespace std;

vector<int> a[101]; 
int b[101],cnt = 0;

void dfs(int x) 
{
	b[x] = 1;
	for (int i = 0; i < a[x].size(); i++) 
	{
		int y = a[x][i];
		if (!b[y]) 
		{
			dfs(y);
			cnt++;
		}
	}
}
int main() 
{
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	cout << cnt;
}