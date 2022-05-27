#include<iostream>
#include<queue>

using namespace std;
int F, G, S, U, D;
queue<pair<int, int>> q;
int visit[1000001];

int bfs(int x)
{
	q.push(make_pair(x, 0));
	visit[x] = 1;
	while (!q.empty())
	{
		int a = q.front().first;
		int cnt = q.front().second;	
		q.pop();
														//visit[a] = 1;
		if (a == G)
			return cnt;
		int up = a + U;
		int down = a - D;
		if (up <= F && !visit[up])
		{
			q.push(make_pair(up, cnt + 1));
			visit[up] = 1;								//밖에서 방문처리를 하면 그 queue부분이 처리될 때까지 방문 안한걸로 됨!!
		}												//따라서 중복으로 queue에 적제됨!!
		if (down > 0 && !visit[down])
		{
			q.push(make_pair(down, cnt + 1));
			visit[down] = 1;
		}
	}
	return -1;											
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	int result = bfs(S);
	if (result!=-1)										// if(result)
		cout <<result;									//한번에 되는 경우는 0인데 0일땐 처리 안됨!
	else
		cout << "use the stairs";
}