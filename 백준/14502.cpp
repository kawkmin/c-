#include<iostream>
#include<queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MAX = 0;
int N, M,a[9][9],b[9][9];

void bfs()
{
	queue<pair<int, int>> q;
	int ab[9][9];
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ab[i][j] = b[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ab[i][j] == 2)
			{
				q.push({ i, j });
			}
		}
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ax =x+ dx[i];
			int ay =y+ dy[i];
			if (ax >= 0 && ay >= 0 && ax < M && ay < N )
			{
				if (ab[ay][ax] == 0)
				{
					ab[ay][ax] = 2;
					q.push({ ay,ax });
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ab[i][j] == 0)
				cnt++;
		}
	}
	MAX = max(cnt, MAX);
}

void wall(int x)
{
	if (x == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (b[i][j] == 0)
			{
				b[i][j] = 1;
				wall(x + 1);
				b[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0)
			{
				b[i][j] = 1;
				wall(1);
				b[i][j] = 0;
			}
		}
	}
	cout << MAX;
}