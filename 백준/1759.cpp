#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int L, C;
char c[16];

void dfs(string x,int depth,int cnt,int b,int b2,int b3)  //아 그냥 b2 > 2로 하면 되는뎅..
{
	if (cnt == L && b && b2 && b3)
	{
		cout << x<<"\n";
		return;
	}
	if (depth == C)
		return;
	if (c[depth] == 'a' || c[depth] == 'e' || c[depth] == 'i' || c[depth] == 'o' || c[depth] == 'u')
		dfs(x + c[depth], depth + 1, cnt + 1, 1, b2, b3);
	else if (b2)
		dfs(x + c[depth], depth + 1, cnt + 1, b, b2, 1);
	else
		dfs(x + c[depth], depth + 1, cnt + 1, b, 1, b3);
	dfs(x, depth + 1,cnt,b,b2,b3);
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> c[i];
	sort(c, c + C);
	string s;
	dfs(s, 0, 0,0,0,0);
}