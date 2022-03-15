#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	queue<int> q;
	vector<int> v[32001];
	int N, M, result[32001], ind[32001] = { 0, }, a, b;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0) q.push(i);
	}
	for (int i = 1; i <= N; i++)
	{
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (--ind[y] == 0)
				q.push(y);
		}
	}


	for (int i = 1; i <= N; i++)
	{
		cout << result[i]<<" ";
	}
}
