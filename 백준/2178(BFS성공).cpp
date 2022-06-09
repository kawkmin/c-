#include<iostream>
#include<queue>
using namespace std;

char a[101][101];
int value[101][101];
int N, M;
int ch[101][101] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


void mage(int xx,int yy)
{
	ch[xx][yy] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(xx, yy));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int ax = x + dx[k];
			int ay = y + dy[k];

			if (ax >= 0 && ay >= 0 && ax < N && ay < M && ch[ax][ay] == 0 && a[ax][ay] == '1')
			{
				value[ax][ay] = value[x][y] + 1;
				ch[ax][ay] = 1;                     //순회하는 부분은 탐색하지 않음 
				q.push(make_pair(ax, ay));		    //dfs일 경우 나오면서 visit을 다 0으로 바꿔줘서 최단거리가 아닌 곳도 무조건 다 감
			}										//예를 들어 (5,5)의 위치를 가는데 dfs는 그 거리를 둘러가서 가는데 bfs는 최단으로만 감
		}
	}

}

int main()
{
	ch[0][0] = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}
	mage(0,0);
	cout << value[N-1][M-1]+1;
}