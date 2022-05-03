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
				ch[ax][ay] = 1;
				q.push(make_pair(ax, ay));
			}
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