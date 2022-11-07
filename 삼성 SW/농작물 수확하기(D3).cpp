#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int N,ans;
int visit[50][50] = { 0, };
int map[50][50];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visit, 0, sizeof(visit));
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			ans = 0;
			if (i == N / 2) continue;
			
			int a = abs(N / 2 - i);
			for (int j = 0; j < N; j++)
			{
				if (j < a || N - j <= a) visit[i][j] = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < N; j++)
				map[i][j] = s[j] - '0';
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
					ans += map[i][j];
			}
		}
		
		cout << "#" << test_case <<" "<<ans<< "\n";
	}
	return 0;
}
