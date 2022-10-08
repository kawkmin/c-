#include <iostream>

using namespace std;
int R, C;
char board[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int alpha[27];
int cnt = 0;

void dfs(int y, int x,int dep)
{
	cnt = max(cnt, dep);
	for (int i = 0; i < 4; i++)
	{
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (ax >= 0 && ay >= 0 && ax < C && ay < R && !alpha[board[ay][ax] - 'A'])
		{
			alpha[board[ay][ax] - 'A'] = 1;
			dfs(ay, ax, dep + 1);
			alpha[board[ay][ax] - 'A'] = 0;
		}
	}
}

int main() 
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	alpha[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << cnt;
}