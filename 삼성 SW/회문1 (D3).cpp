#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
string s[10];
int N,ans;
int visit[10] = { 0, };

bool valid(string s)
{
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] == s[s.length()-1-i]) 
			continue;
		else 
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		ans = 0;
		cin >> N;
		for (int i = 0; i < 8; i++)
			cin >> s[i];
		for (int t = 0; t < 8; t++)
		{
			for (int i = 0; i < 8 - N+1; i++)
			{
				string str = "";
				string str2 = "";
				for (int j = i; j < i + N; j++)
				{
					str += s[t][j];
					str2 += s[j][t];
				}
				if (valid(str))
					ans++;
				if (valid(str2))
					ans++;
			}
		}
		cout << "#" << test_case <<" "<<ans<< "\n";
	}
	return 0;
}

