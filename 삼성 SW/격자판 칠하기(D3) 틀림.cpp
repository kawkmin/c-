#include<iostream>
using namespace std;

char a[51][51];

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int b;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> a[i][j];

		for (int i = 0; i < 2; i++)
		{
			b = 1;
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (a[j][k] == '?')
						continue;
					if ((j + k) % 2 == i)
					{
						if (a[j][k] != '.')
							b = 0;
					}
					else
						if (a[j][k] != '#')
							b = 0;
				}
			}
			if (b == 1)
				break;
		}
		
		if (b)
			cout << "#" << test_case << " possible" << "\n";
		else
			cout << "#" << test_case << " impossible" << "\n";
	}
	return 0;
}