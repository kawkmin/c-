#include <iostream>
#include<queue>
using namespace std;
int N, map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[101][101];
int vvist[101][101];

bool bfs(int x, int y, int x2, int y2) //같은 섬인지 판별인데 바로 이전칸만 확인해서 오류
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			visit[i][j] = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visit[y][x] = 1;
	while (!q.empty())
	{
		int adx = q.front().second;
		int ady = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ax = adx + dx[i];
			int ay = ady + dy[i];
			if (ax >= 0 && ay >= 0 && ax < N && ay < N && map[ay][ax] == 1 && !visit[ay][ax])
			{
				q.push({ ay,ax });
				visit[ay][ax] = 1;
			}
		}
	}
		if (visit[y2][x2])
			return false;
		else
			return true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	queue<pair<pair<int,int>,int>> qq;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
				qq.push({ {i,j},0 });
		}
	}
	while (!qq.empty())
	{	
		int x = qq.front().first.second;
		int y = qq.front().first.first;
		int d = qq.front().second;
		
		cout << x << " " << y <<" " << d << "\n";
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ax = x + dx[i];
			int ay = y + dy[i];
			if (ax >= 0 && ay >= 0 && ax < N && ay < N  && bfs(x, y, ax, ay))
			{
				if (!map[ay][ax])
				{
					qq.push({ { ay,ax }, d + 1 });
				}
				else if (d > 0 && map[ay][ax])
				{
					cout << d<<" "<<ax<<" "<<ay;
					return 0;
				}
			}
		}
	}
}