#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = true; //방문 했다는 뜻
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d", x);
		for (int i = 0; i < a[x].size()/*바로 밑 참고 인접한 수 만큼*/; i++)
		{
			int y = a[x][i];//x에 인접한걸 벡터배열로 표현(i가 인접함) a[1][0] 1에 인접한 2란뜻
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}


int main()
{
	a[1].push_back(2);// 1과 2를 연결합니다.
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);
}