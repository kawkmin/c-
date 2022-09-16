#include<iostream>

using namespace std;

int N,a[100001][4];
int dpmax[100001][4], dpmin[100001][4];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			dpmin[i][j] = 999999;
		}
	}
	
	for (int i = 1; i <= 3; i++)
		dpmin[1][i] = a[1][i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			dpmax[i][j] = max(dpmax[i - 1][j - 1], dpmax[i - 1][j]);
			dpmax[i][j] = max(dpmax[i][j], dpmax[i - 1][j + 1]);
			dpmax[i][j] += a[i][j];

		}
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			dpmin[i][j] = min(dpmin[i - 1][j - 1], dpmin[i - 1][j]);
			dpmin[i][j] = min(dpmin[i][j], dpmin[i - 1][j + 1]);
			dpmin[i][j] += a[i][j];
		}
	}
	int MAX=0, MIN=999999;
	for (int i = 1; i <= 3; i++)
	{
		if (MAX < dpmax[N][i])
			MAX = dpmax[N][i];

		if (MIN > dpmin[N][i])
			MIN = dpmin[N][i];
	}
	cout << MAX<<" "<<MIN;

}