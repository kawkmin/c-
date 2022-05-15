#include<iostream>
#include <vector>
#include<queue>

using namespace std;
int M, N, H;
vector<int> v[102][102];
int visit[102][102][102];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>> q;
int cnt = 0;

int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int x;
				cin >> x;
				v[i][j].push_back(x);
				if (x == 1)
				{
					q.push({ { i,j }, k });
				}
				if (x == 0)
					visit[i][j][k] = -1;
			}
		}
	}
	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ax = cur.first.second + dx[i];
			int ay = cur.second + dy[i];
			int az = cur.first.first + dz[i];

			if (ax >= 0 && ax < N && ay >= 0 && ay < M && az >= 0 && az < H && visit[az][ax][ay]<0)
			{
				visit[az][ax][ay] = visit[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ { az,ax },ay });
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (visit[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				cnt = max(cnt, visit[i][j][k]);
			}
		}

	}
	cout << cnt;
}