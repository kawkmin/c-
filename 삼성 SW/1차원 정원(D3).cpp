#include<iostream>

using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, D;
		cin >> N >> D;
		int x = D * 2 + 1;
		int cnt = N / x;
		if (N % x)
			cnt++;
		cout << "#" << test_case << " "<<cnt << "\n";
	}
	return 0;
}