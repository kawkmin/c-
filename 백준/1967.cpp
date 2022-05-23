#include <iostream>
#include<vector>

using namespace std;
vector<pair<int,int>> v[10001];
int n, result = 0;

int dfs(int x)
{
	int len1 = 0;
	int len2 = 0;

	for (int i = 0; i < v[x].size(); i++)
	{
		int a =dfs(v[x][i].first)+v[x][i].second;
		if (len1 < a)
		{
			len2 = len1;
			len1 = a;
		}
		else if (len2 < a)
			len2 = a;
	}
	result = max(result, len1 + len2);

	return len1;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dfs(1);
	cout << result;
}