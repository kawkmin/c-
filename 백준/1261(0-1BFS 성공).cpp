#include<iostream>
#include<deque>
using namespace std;

int ax[4] = { 0,0,1,-1 };
int ay[4] = { 1,-1,0,0 };
char arr[101][101];
int visit[101][101];
int result[101][101];
deque <pair<int,pair<int,int>>> q;

int main()
{
	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	q.push_back({ 0,{ 0,0 } });
	visit[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().second.second;
		int y = q.front().second.first;
		int cnt = q.front().first;
		q.pop_front();
		if (y == N - 1 && x == M - 1)
		{
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int dx = x + ax[i];
			int dy = y + ay[i];
			if (dx >= 0 && dy >= 0 && dx < M && dy < N&&!visit[dy][dx])
			{
				if (arr[dy][dx] == '1')
				{
					q.push_back({ cnt + 1,{dy,dx} });
				}
				else
				{
					q.push_front({ cnt,{dy,dx} });
				}
				visit[dy][dx] = 1;
			}
		}
	}
	/*cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << result[i][j];
		}
		cout << "\n";
	}*/
	/*cout << cnt;*/
}