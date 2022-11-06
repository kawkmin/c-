#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string x = "ADOPQR";
		string y = "CEFGHIJKLMNSTUVWXYZ";
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == 'B') continue;
			for (int j = 0; j < x.length(); j++)
			{
				if (s1[i] == x[j])
				{
					s1[i] = 'x';
					continue;
				}
			}
			for (int j = 0; j < y.length(); j++)
			{
				if (s1[i] == y[j])
				{
					s1[i] = 'y';
					continue;
				}
			}
		}
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] == 'B') continue;
			for (int j = 0; j < x.length(); j++)
			{
				if (s2[i] == x[j])
				{
					s2[i] = 'x';
					continue;
				}
			}
			for (int j = 0; j < y.length(); j++)
			{
				if (s2[i] == y[j])
				{
					s2[i] = 'y';
					continue;
				}
			}
		}
		if(s1==s2)
			cout << "#" << test_case << " SAME" << "\n";
		else
			cout << "#" << test_case << " DIFF" << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

