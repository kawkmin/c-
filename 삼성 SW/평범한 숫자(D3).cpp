#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int x, p[21], cnt = 0;
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			cin >> p[i];
		}
		for (int i = 1; i < x - 1; i++)
		{
			if (p[i - 1] < p[i])
			{
				if (p[i + 1] > p[i])
					cnt++;
			}
			else if (p[i - 1] > p[i])
				if (p[i + 1] < p[i])
					cnt++;
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}