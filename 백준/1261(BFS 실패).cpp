#include<iostream>
#include<queue>
using namespace std;

int ax[4] = { 0,0,1,-1 };
int ay[4] = { 1,-1,0,0 };
char arr[101][101];
int visit[101][101];
int result[101][101];
int cnt = 0;
queue <pair<int,int>> q;

int main()
{
	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int dx = x + ax[i];
			int dy = y + ay[i];
			if (dx >= 0 && dy >= 0 && dx < M && dy < N&&!visit[dy][dx]) // visit을 안쓰고 갱신 해야하는데 모르겠움
			{
				if (arr[dy][dx] == '1')
				{
					result[dy][dx] = result[y][x] + 1;
				}
				else
					result[dy][dx] = result[y][x];
				visit[dy][dx] = 1;
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << result[i][j];
		}
		cout << "\n";
	}
	cout << result[N-1][M-1];
}