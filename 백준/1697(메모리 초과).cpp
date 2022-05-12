#include <iostream>
#include<queue>

using namespace std;
queue<pair<int,int>> q;
int N, K,mn=987654321;
int dx[2] = { -1,1 };

void bfs(int a)
{
	q.push(make_pair(a,0));
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		if (cnt > mn)
		{
			q.pop();
			return;
		}
		if (x == K)
		{
			if (cnt < mn)
			{
				mn = cnt;
			}
			q.pop();
			return;
		}
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int ax;
			if (i == 2)
				ax= x*2;
			else
				ax = x+dx[i];
			if(ax>=0&&ax<=100000)
				q.push(make_pair(ax, cnt+1));
		}
	}
}

int main()
{
	cin >> N >> K;
	bfs(N);
	cout << mn;
}
