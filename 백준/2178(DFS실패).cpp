#include<iostream>

using namespace std;

char a[101][101];
int N, M,cnt=1;
int ch[101][101] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int Min=10001;
void mage(int x,int y,int d)
{
	if (x == N - 1 && y == M - 1)
	{
		if (d < Min)
			Min = d;
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		int ax = x + dx[k];
		int ay = y + dy[k];
		
		if (ax >= 0 && ay >= 0 && ax < N && ay < M && ch[ax][ay] == 0 && a[ax][ay] == '1')
		{
			ch[x][y] = 1;
			mage(ax, ay,d+1);
			ch[x][y]=0;
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
	mage(0,0,1);
	cout << Min;
}