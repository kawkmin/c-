#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;
		int a[26] = { 0, };
		for (int i = 0; i < s.size(); i++)
		{
			a[s[i] - 'A'] += 1;
		}
		int result = 0;
		for (int i = 0; i < 26; i++)
		{
			if (a[i] == 2)
				result++;
		}
		if (result == 2)
			cout << "#" << test_case << " Yes" << "\n";
		else
			cout << "#" << test_case << " No" << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

