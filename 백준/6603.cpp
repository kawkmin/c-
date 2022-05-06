#include<iostream>

using namespace std;

int k,s[13];
int a[6];

void dfs(int start, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << a[i];
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++)
	{
		a[depth] = s[i];
		dfs(i + 1, depth + 1);
	}

}

int main()
{
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
		}
		dfs(0, 0);
		cout << "\n";
	}
}