#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, a[7], MIN = 123456789;
		cin >> n;
		for (int i = 0; i < 7; i++)
			cin >> a[i];
		for (int i = 0; i < 7; i++)
		{
			if (a[i] == 1)
			{
				int tempn = n;
				int cnt = 0;
				int x = i;
				while (tempn)
				{
					if (x == 7)
						x = 0;
					if (a[x] == 1)
					{
						tempn--;
					}
					cnt++;
					x++;
				}
				MIN = min(MIN, cnt);
			}
		}
		cout << "#" << test_case << " " << MIN << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

