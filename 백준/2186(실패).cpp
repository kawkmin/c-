#include<iostream>

using namespace std;

char a[101][101];
int visit[101][101]; //문제를 잘 읽자 여러번 방문 가능...
int N, M, K, cnt = 0;
string s;
int addx[4] = { 0,0,1,-1 };
int addy[4] = { 1,-1,0,0 };

//시간 초과 dp 사용 해야함
void dfs(int y, int x, int dep)
{
	if (dep == s.size() )
	{
		cnt++;
		return;
	}

	for (int j = 0; j < 4; j++)
	{
		int ax=x,ay=y;
		for (int i = 0; i < K; i++)
		{
			ax = ax + addx[j];
			ay = ay + addy[j];

			if (ax >= 0 && ay >= 0 && ax < M && ay < N && !visit[ay][ax] && a[ay][ax] == s[dep])
			{
				visit[ay][ax] = 1;
				dfs(ay, ax, dep+1);
				visit[ay][ax] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> a[i][j];
	}
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == s[0])
			{
				visit[i][j] = 1;
				dfs(i, j, 1);
			}
		}
	}
	cout << cnt;
}