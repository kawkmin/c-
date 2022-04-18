#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char s[50][50];
int c[50][50];
int w, h,cnt=0;

int dx[8] = { 1,-1,0,0 ,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1 ,1,-1,1,-1 };


void DFS(int x, int y)
{
	c[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >=0 && nx < h && ny < w && c[nx][ny] == false && s[nx][ny] == '1')
		{
			DFS(nx, ny);
		}
	}
}

int main()
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				c[i][j] = 0;
				s[i][j] = '0';
			}
		}
		cnt = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> s[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (s[i][j] == '1' && c[i][j] == false)
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt<<"\n";
	}
}