#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int>q;
vector<int>v[501];

int main()
{
	int N, ind[501] = { 0, }, a[501], b, result[501] = { 0, };
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		while (1)
		{
			cin >> b;
			if (b == -1) break; 
			ind[i]++;
			v[b].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0)
		{
			result[i] = a[i]; //Ãß°¡
			q.push(i);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			result[y] = max(result[y], result[x] + a[y]);
			if (--ind[y] == 0)
			{
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << "\n";
	}
}
