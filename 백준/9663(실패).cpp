#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int ans, N;
int board[15];

bool isvalid(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (board[x] == board[i]) return false;
		if (abs(board[x] - board[i]) == abs(x - i)) return false;
	}
	return true;
}

void queen(int cnt)
{
	if (cnt == N)
	{
		ans++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		board[cnt] = i;
		if (isvalid(cnt))
			queen(cnt + 1);
	}
}

int main()
{
	ans = 0;
	cin >> N;
	memset(board, 0, sizeof(board));
	queen(0);
	cout << ans;
}

