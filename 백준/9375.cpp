#include<iostream>
#include<map>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		string s;
		string s2;
		map<string, int> m;

		for (int i = 0; i < n; i++)
		{
			cin >> s>>s2;
			m[s2]++;
		}
		int ans = 1;
		
		for (auto a : m)
		{
			ans *= (a.second+1);
		}
		cout << ans - 1<<"\n";
	}
}

