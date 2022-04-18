#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> v[26];
int c[26][26];
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
string str[26];
int ccount = 0;
vector<int> value;

void DFS(int x, int y)
{
	c[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		if (x+dx[i]>=0 && y + dy[i] >= 0 && x + dx[i] <n && y + dy[i] <n &&c[x+dx[i]][y+dy[i]]==false && str[x + dx[i]][y + dy[i]] == '1')
		{
			DFS(x + dx[i], y + dy[i]);
			ccount++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == '1' && c[i][j] == false)
			{
				ccount = 1;
				DFS(i, j);
				value.push_back(ccount);
			}
		}
	}
	cout << value.size() << "\n";
	sort(value.begin(), value.end());
	for (int i = 0; i < value.size(); i++)
	{
		cout << value[i] << "\n";
	}
}