#include<iostream>

using namespace std;

char a[101][101];
int dp[101][101][101];
int N, M, K, cnt = 0;
string s;
int addx[4] = { 0,0,1,-1 };
int addy[4] = { 1,-1,0,0 };

int dfs(int y, int x, int dep)
{
	if (dep == s.size())
	{
		dp[y][x][dep] = 1;
		return 1;
	}
	if (dp[y][x][dep] != -1)
		return dp[y][x][dep];

	dp[y][x][dep] = 0;
	for (int j = 0; j < 4; j++)
	{
		int ax=x ,ay=y;
		for (int i = 0; i < K; i++)
		{
			ax = ax + addx[j];
			ay = ay + addy[j];
			if (ax >= 0 && ay >= 0 && ax < M && ay < N  && a[ay][ax] == s[dep])
			{
				dp[y][x][dep]+=dfs(ay, ax, dep+1);
			}
		}
	}
	return dp[y][x][dep];
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 101; k++)
				dp[i][j][k] = -1;

	cin >> s;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == s[0])
			{
				cnt+=dfs(i, j, 1);
			}
		}
	}
	cout << cnt;
}