#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int>q;
vector<int>v[501];

int main() //value로 하면 애초에 위상정렬 필요가없음 
{
	int N, ind[501] = { 0, }, a[501], b, value[501], result[501];
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		value[i] = a[i];
		while (1)
		{
			cin >> b;
			if (b == -1) break; 
			ind[i]++;
			value[i] += a[b];
			v[i].push_back(b);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0) q.push(i);
	}
	for (int i = 1; i <= N; i++)
	{
		int x = q.front();
		q.pop();
		result[i] = value[x];
		for (int i = 0; i <= v[x].size(); i++)
		{
			int y = v[x][i];
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
