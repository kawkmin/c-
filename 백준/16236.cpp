#include<iostream>
#include<queue>
using namespace std;

int dx[8] = { 1,-1,0,0,1,-1,1 ,-1};
int dy[8] = { 0,0,1,-1,1,-1 ,-1,1};
queue<pair<pair<int, int>, int>> q1;
queue<pair<pair<int, int>, int>> q2;

int N, M, map[51][51];
int a = 0;

void bfs()
{
	int visit[51][51] = { 0, };
	while (!q2.empty()) 
	{
		int x2 = q2.front().first.second;
		int y2 = q2.front().first.first;
		int d2 = q2.front().second;
		visit[y2][x2] = 1;
		q2.pop();
		for (int i = 0; i < 8; i++)
		{
			int ax = x2 + dx[i];
			int ay = y2 + dy[i];
			if (ax >= 0 && ay >= 0 && ax < M && ay < N&&!visit[ay][ax])
			{
				if (map[ay][ax] == 0)
				{
					visit[ay][ax] = 1;
					q2.push({ { ay,ax }, d2 + 1 });
				}
				else
				{
					a = max(a, d2 + 1);
					int size = q2.size();
					for (int z = 0; z < size; z++)
						q2.pop();
					return;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				q1.push({ {i,j,},0 });
		}
	while (!q1.empty())
	{
		q2.push({ {q1.front().first.first,q1.front().first.second},0 });
		bfs();
		q1.pop();
	}
	cout << a;
}