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
			visit[up] = 1;								//�ۿ��� �湮ó���� �ϸ� �� queue�κ��� ó���� ������ �湮 ���Ѱɷ� ��!!
		}												//���� �ߺ����� queue�� ������!!
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
		cout <<result;									//�ѹ��� �Ǵ� ���� 0�ε� 0�϶� ó�� �ȵ�!
	else
		cout << "use the stairs";
}