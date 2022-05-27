#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int L, C;
char c[16];
vector<char> res;

bool check()
{
	int nu = 0;
	for (int i =0; i < L; i++)
	{
		if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
			nu++;
	}
	if (nu >= 1 && L - nu >= 2)
		return true;
	else 
		return false;
}

void dfs(int x)
{
	if (res.size() == L)
	{
		if (check())
		{
			for (int k = 0; k < L; k++)
				cout << res[k];
			cout << "\n";
		}
		return;
	}
	for (int i = x; i < C; i++)
	{
		res.push_back(c[i]);
		dfs(i + 1);
		res.pop_back();
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> c[i];
	sort(c, c + C);
	dfs(0);
}