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
				co = 1;     //�ѳ�忡 2���̻� ���� �־����� ���� �˸��� �ʰ� �־���,���� ���̶� �ٸ����� �־����
			                //������ �ѹ� ������ 2������ ������ 1�� ���� �ݺ�
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
		dfs(1); //���� ���� �������� 
		if (b)
			cout << "YES\n";
		else if (!b)
			cout << "NO\n";
		//b�� �ٽ� �ʱ�ȭ �ؾ���
	}
}