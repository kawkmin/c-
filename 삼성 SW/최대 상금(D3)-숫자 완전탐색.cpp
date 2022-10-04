#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int C, ans;
string s;

void dfs(int x, int cnt)
{
	if (cnt == C)
	{
		ans = max(stoi(s), ans);
		return;
	}
	for (int i = x; i < s.size() - 1; i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			swap(s[i], s[j]);
			dfs(i, cnt + 1);
			swap(s[i], s[j]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s >> C;
		ans = 0;
		if (C > s.size())
			C = s.size(); //원하는 수로 바꿀려면 최대라도 그 수 크기만큼만 필요함
		dfs(0, 0);
		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}