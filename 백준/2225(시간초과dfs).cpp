#include<iostream>

using namespace std;
int N, K;
long long int sum = 0;

void dfs(int x, int depth)
{
	if (depth == K)
	{
		if (x == N)
			sum++;
		sum %= 1000000000;
		return;
	}
	for (int i = 0; i <= N; i++)
		dfs(x + i, depth + 1);
}

int main()
{
	cin >> N >> K;
	dfs(0, 0);
	cout << sum;
}