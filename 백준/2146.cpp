#include <iostream>
#include<queue>
using namespace std;
int N, map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[101][101];
int K[101][101];
int result = 987654321;
int cnt = 0;

void bfs(int x, int y, int key)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visit[y][x] = 1;
	while (!q.empty())
	{
		int b = 0;
		int adx = q.front().second;
		int ady = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ax = adx + dx[i];
			int ay = ady + dy[i];
			if (ax >= 0 && ay >= 0 && ax < N && ay < N)
			{
				if (!visit[ay][ax] && map[ay][ax] == 1)
				{
					visit[ay][ax] = 1;
					q.push({ ay,ax });
				}
				if (map[ay][ax] == 0)
				{
					K[ady][adx] = key;
					b = 1;
				}
			}
		}
		if (!b)
			K[ady][adx] = -1;
	}
}

void bfs2(int x, int y, int key)
{
	queue<pair<pair<int,int>, int>> q;
	q.push({ { y,x },0 });
	visit[y][x] = 1;
	while (!q.empty())
	{
		int adx = q.front().first.second;
		int ady = q.front().first.first;
		int d = q.front().second;
		q.pop();
		if (K[ady][adx] != 0 && K[ady][adx] != key)
		{
			result = min(result, d);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int ax = adx + dx[i];
			int ay = ady + dy[i];
			if (ax >= 0 && ay >= 0 && ax < N && ay < N && !visit[ay][ax] && K[ay][ax]>=0 && K[ay][ax] != key)
			{
				visit[ay][ax] = 1;
				q.push({ {ay,ax},d + 1 });
			}
		}
	}
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	int k = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j])
			{
				bfs(j, i, k);
				k++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					visit[a][b] = 0;
			if (K[i][j] > 0)
				bfs2(j, i, K[i][j]);
		}
	}
	cout<< result-1;
}