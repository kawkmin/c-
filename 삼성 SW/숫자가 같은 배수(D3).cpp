#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int b = 0;
string s;

void TF(int x)
{
	string sx = to_string(x);
	if (s.size() != sx.size())
	{
		b = 2;
		return;
	}
	string temps = s;
	sort(temps.begin(), temps.end());
	sort(sx.begin(), sx.end());
	if (sx == temps)
		b = 1;
}

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		b = 0;
		cin >> s;
		int n = stoi(s);
		for (int i = 2; i < 10; i++)
		{
			int x = n * i;
			TF(x);
			if (b == 2||b==1)
				break;
		}
		if (b==1)
			cout << "#" << test_case << " possible" << "\n";
		else
			cout << "#" << test_case << " impossible" << "\n";
	}
	return 0;
}