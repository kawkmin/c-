#include<iostream>
#include <vector>

using namespace std;
int M, N, H;
vector<int> v[100000];
int visit[100000][102];
int vvisit[100000][102];
int dx[6] = { 1,-1,0,0};
int dy[6] = { 0,0,1,-1,0,0};

int tf()
{
	for (int i = 0; i < N * H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == 0)
				return false;
		}
	}
	return true;
}

void dfs(int a,int b)
{
	if (v[a][b] == 1&&!vvisit[a][b])
	{
		for (int i = 0; i < 6; i++)
		{
			int x = a + dx[i];
			int y = b + dy[i];
			if (x >= 0 && y >= 0 && x < N * H && y < M && v[x][y] == 0)
			{
				v[x][y] = 1;
				vvisit[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int x = a + dx[i];
		int y = b + dy[i];
		if (x >= 0 && y >= 0 && x < N * H && y < M && !visit[x][y])
		{
			visit[x][y] = 1;
			dfs(x, y);
		}
	}

}

int main()
{
	cin >> M >> N >> H;
	dx[4] = N;
	dx[5] = -N;
	for (int i = 0; i < N*H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		if (tf())
			break;
		dfs(0, 0);
		cnt++;
		for (int i = 0; i < N * H; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visit[i][j] = 0;
				vvisit[i][j] = 0;
			}
		}
	}
	/*dfs(0, 0);
	for (int i = 0; i < N * H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}*/
	if (cnt == 100)
		cout << "-1";
	else
		cout << cnt;

}