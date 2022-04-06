#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> v[26];
int c[26][26];
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
string str[26];
int ccount=0;
vector<int> value;
void BFS(int x,int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	c[x][y] = true;
	ccount++;
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (0 <= nx && 0 <= ny && nx < n && ny < n && c[nx][ny] == false && str[nx][ny] == '1') //순서 중요
			{
				q.push({ nx,ny });
				c[nx][ny] = true;
				ccount++;
			}
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
				ccount = 0;
				BFS(i, j);
				value.push_back(ccount);
			}
		}
	}
	cout << value.size()<<"\n";
	sort(value.begin(), value.end());
	for (int i = 0; i < value.size(); i++)
	{
		cout << value[i] << "\n";
	}
}
