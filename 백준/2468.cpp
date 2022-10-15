#include<iostream>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[101][101];
int tempmap[101][101];
int N,map[101][101],result=1;

void dfs(int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (ay >= 0 && ax >= 0 && ax < N && ay < N && !visit[ay][ax] && tempmap[ay][ax] == 1)
			dfs(ay, ax);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int z = 1; z < 99; z++)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > z)
					tempmap[i][j] = 1;
				else
					tempmap[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > z&&!visit[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		result = max(result, cnt);
	}
	cout << result;
}