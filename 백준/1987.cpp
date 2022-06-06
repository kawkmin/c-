#include<iostream>
#include<vector>

using namespace std;

int R, C;
char v[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int alpha[26];
int cnt = 0;

void dfs(int y, int x, int cn)
{
	cnt = max(cn, cnt);
	for (int i = 0; i < 4; i++)
	{
		int vx = x + dx[i];
		int vy = y + dy[i];
		if (vx >= 0 && vy >= 0 && vx < C && vy < R && !alpha[v[vy][vx] - 'A'])
		{
			alpha[v[vy][vx] - 'A'] = 1;
			dfs(vy, vx, cn + 1);
			alpha[v[vy][vx] - 'A'] = 0;
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> v[i][j];
		}
	}
	alpha[v[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << cnt;
}