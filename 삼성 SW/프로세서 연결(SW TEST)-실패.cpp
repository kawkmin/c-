#include<iostream>

using namespace std;
int map[12][12];
int N, CNT = 0, MIN = 1234567;
int visit[12][12];

void dfs(int x, int y, int sum, int cnt)
{
	if (cnt == CNT)
	{
		MIN = min(sum, MIN);
		return;
	}
	for (int i = y; i < N; i++)
	{
		for (int j = x; j < N; j++) //순서대로 계속해서 할려고 하는데 다음 y의 x위치가 0부터 안됨
		{
			if (map[i][j] == 1)
			{
				if (i != y && j != x)
				{

					if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
						dfs(j, i, sum, cnt + 1);

					else
					{

						bool b = false;

						bool B = true;
						for (int z = 0; z < j; z++)
							if (visit[i][z])
								B = false;
						if (B)
						{
							b = true;
							for (int z = 0; z < j; z++)
								visit[i][z] = 1;

							dfs(j, i, sum + j, cnt + 1);
							for (int z = 0; z < j; z++)
								visit[i][z] = 0;
						}

						B = true;
						for (int z = 0; z < i; z++)
							if (visit[z][j])
								B = false;
						if (B)
						{
							b = true;
							for (int z = 0; z < i; z++)
								visit[z][j] = 1;
							dfs(j, i, sum + i, cnt + 1);
							for (int z = 0; z < i; z++)
								visit[z][j] = 0;
						}

						B = true;
						for (int z = j + 1; z < N; z++)
							if (visit[i][z])
								B = false;
						if (B)
						{
							b = true;
							for (int z = j + 1; z < N; z++)
								visit[i][z] = 1;
							dfs(j, i, sum + N - j, cnt + 1);
							for (int z = j + 1; z < N; z++)
								visit[i][z] = 0;
						}

						B = true;
						for (int z = i + 1; z < N; z++)
							if (visit[z][j])
								B = false;
						if (B)
						{
							b = true;
							for (int z = i + 1; z < N; z++)
								visit[z][j] = 1;
							dfs(j, i, sum + N - i, cnt + 1);
							for (int z = i + 1; z < N; z++)
								visit[z][j] = 0;
						}

						if (!b)
							return;
					}

				}
			}
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
		MIN = 1234567;
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					CNT++;
					visit[i][j] = 1;
				}
			}
		dfs(0, 0, 0, 0);
		cout << "#" << test_case << " " << MIN << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

