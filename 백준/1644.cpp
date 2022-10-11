#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[4000001],temp[4000001];
int N,cnt=0;
int index = 0;

void dfs(int x,int dep)
{
	if (dep >= index)
		return;
	x += temp[dep];
	if (x == N)
	{
		cnt++;
		return;
	}
	if (x > N)
		return;
	dfs(x , dep +1);
}

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++)
		a[i] = i;
	for (int i = 2; i <= N; i++)
	{
		if (a[i] == 0) 
			continue;
		for (int j = i + i; j <=N; j += i)
		{
			a[j] = 0;
		}
	}
	for (int i = 2; i <=N; i++)
	{
		if (a[i])
		{
			temp[index] = a[i];
			index++;
		}
	}

	for (int i = 0; i < index; i++)
		dfs(0, i);
	cout << cnt;
}