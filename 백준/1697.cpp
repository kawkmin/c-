#include <iostream>
#include<queue>

using namespace std;
queue<pair<int, int>> q;
int N, K, mn ;
int dx[2] = { -1,1 };
int visit[100001];    //방문한 지점을 다시 q에 넣으면 메모리초과+시간 오래걸림

void bfs(int a)
{
	q.push(make_pair(a, 0));
	visit[a] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		if (x == K)
		{
			mn = cnt;              //발견한게 바로 최소값임 bfs
			q.pop();
			return;
		}
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int ax;
			if (i == 2)
				ax = x * 2;
			else
				ax = x + dx[i];
			if (ax >= 0 && ax <= 100000 && !visit[ax])
			{
				q.push(make_pair(ax, cnt + 1));
				visit[ax] = 1;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	bfs(N);
	cout << mn;
}
