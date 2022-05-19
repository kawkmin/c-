#include<iostream>

using namespace std;
int N,M;
int a[51][51];
long long result = 0;

int getsum(int startx, int starty,int endx,int endy)
{
	int x=0;
	for (int i = startx; i <= endx; i++)
	{
		for (int j = starty; j <= endy; j++)
		{
			x += a[i][j];
		}
	}
	return x;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			long long a = getsum(0,0,i,M-1);
			long long b = getsum(i+1, 0, j, M-1);
			long long c = getsum(j+1, 0, N-1, M-1);
			result=max(result, a * b * c);
		}
	}
	for (int i = 0; i < M - 2; i++)
	{
		for (int j = i + 1; j < M - 1; j++)
		{
			long long a = getsum(0,0, N - 1,i);
			long long b = getsum(0,i + 1, N - 1,j);
			long long c = getsum(0,j + 1,  N - 1, M - 1);
			result = max(result, a * b * c);
		}
	}
	for (int i = M - 1; i > 0; i--) {
		for (int j = 0; j < N - 1; j++) {
			long long a = getsum(0, i, N - 1, M - 1);
			long long b = getsum(0, 0, j, i - 1);
			long long c = getsum(j + 1, 0, N - 1, i - 1);
			result = max(result, a * b * c);
		}
	}

	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			long long a = getsum(0, 0, N - 1, i);
			long long b = getsum(0, i + 1, j, M - 1);
			long long c = getsum(j + 1, i + 1, N - 1, M - 1);
			result = max(result, a * b * c);
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			long long a = getsum(0, 0, i, M - 1);
			long long b = getsum(i + 1, 0, N - 1, j);
			long long c = getsum(i + 1, j + 1, N - 1, M - 1);
			result = max(result, a * b * c);
		}
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M - 1; j++) {
			long long a = getsum(i, 0, N - 1, M - 1);
			long long b = getsum(0, 0, i - 1, j);
			long long c = getsum(0, j + 1, i - 1, M - 1);
			result = max(result, a * b * c);
		}
	}

	cout << result;
}