#include<iostream>
#include <vector>
#include<queue>

using namespace std;
int M, N;
int a[1001][1001];
int visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<pair<int, int>,int>> q;

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				q.push({ {i,j},0 });
				visit[i][j] = 1;
			}
			else if (a[i][j] == -1)
				visit[i][j] = 1;
		}
	}
	int cnt=0;
	while (!q.empty())
	{
		int x = q.front().first.second;
		int y = q.front().first.first;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ax = x + dx[i];
			int ay = y + dy[i];
			if (ax >= 0 && ax < M && ay >= 0 && ay < N && !visit[ay][ax])
			{
				a[ay][ax] = 1;
				q.push({ { ay,ax },cnt + 1 });
				visit[ay][ax] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
	
}