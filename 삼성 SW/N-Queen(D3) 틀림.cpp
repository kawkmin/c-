#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int ans, N;
int board[10];

bool isvalid(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (board[x] == board[i]) return false;
		if (abs(board[x] - board[i]) == x - i) return false;
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

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		cin >> N;
		memset(board, 0, sizeof(board));
		queen(0);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

