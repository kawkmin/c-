#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N, L;
long long ans;
vector<pair<int, int>> v;

void dfs(int x, int cnt,long long value)
{
	if (cnt > L) return;
	ans = max(value, ans);
	if (x == N) return;
	dfs( x+1, cnt + v[x].second,value+v[x].first);
	dfs(x + 1, cnt, value);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1;t <= T;t++)
	{
		ans = 0;
		v.clear();
		cin >> N >> L;
		for (int i = 0;i < N;i++)
		{
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		dfs(0, 0,0);
		cout << "#" << t << " " <<ans << "\n";
	}
}