#include <iostream>
#include<queue>

using namespace std;
queue<pair<int, int>> q;
int N, K, mn ;
int dx[2] = { -1,1 };
int visit[100001];    //�湮�� ������ �ٽ� q�� ������ �޸��ʰ�+�ð� �����ɸ�

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
			mn = cnt;              //�߰��Ѱ� �ٷ� �ּҰ��� bfs
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
