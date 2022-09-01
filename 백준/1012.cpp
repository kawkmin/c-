#include <iostream>
#include<vector>

using namespace std;

int T, M, N, K;
int v[51][51];
int visit[51][51];
int ax[4] = {1,-1,0,0};
int ay[4] = {0,0,1,-1};

void dfs(int a,int b) 
{

	visit[a][b] = 1;
	for (int i = 0; i < 4; i++)
	{
		int dx = b + ax[i];
		int dy = a + ay[i];
		if (dx < M && dy < N && dx >= 0 && dy >= 0 && !visit[dy][dx] && v[dy][dx])
			dfs(dy, dx);
	}

}

int main()
{
	cin >> T;
	for(int i=0;i<T;i++)
	{
		int x, y,cnt=0;
		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{
				v[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			v[y][x] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i][j] && !visit[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}