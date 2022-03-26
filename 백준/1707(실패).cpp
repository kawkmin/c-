#include<iostream>
#include<vector>

using namespace std;
int c[200001], color[20001], co = 1;
bool b = true;
vector<int> a[20001];

void dfs(int x)
{
	color[x] = co;
	c[x] = true;
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (!c[y])
		{
			if (co == 1)
				co = 2;
			else if (co == 2)
				co = 1;     //한노드에 2개이상 간선 넣어지면 색이 알맞지 않게 넣어짐,지금 색이랑 다른색을 넣어야함
			                //지금은 한번 넣으면 2가들어가고 다음엔 1이 들어가고 반복
			dfs(y);
		}
		if (color[y] == color[x]) 
		{
			b = false;
			return;
		}
	}

}

int main()
{
	int K, V, E, x, y;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		for (int k = 1; k <= V; k++)
		{
			c[k] = false;
			a[k].clear();
		}
		for (int j = 0; j < E; j++)
		{
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1); //끊긴 간선 생각안함 
		if (b)
			cout << "YES\n";
		else if (!b)
			cout << "NO\n";
		//b값 다시 초기화 해야함
	}
}