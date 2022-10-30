#include<iostream>
#include<vector>
using namespace std;
int cnt;

bool istrue(vector<vector<char>>& a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 'O')
			{
				cnt++;
				for (int k = 0; k < 8; k++)
				{
					if (k != j)
						if (a[i][k] == 'O')
							return false;
				}
				for (int k = 0; k < 8; k++)
				{
					if (k != i)
						if (a[k][j] == 'O')
							return false;
				}
			}
		}
	}
	if (cnt == 8)
		return true;
	else
		return false;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cnt = 0;
		vector<vector<char>> map(8);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				char temp;
				cin >> temp;
				map[i].push_back(temp);
			}
		if (istrue(map))
			cout << "#" << test_case << " " << "yes"<<"\n";
		else
			cout << "#" << test_case << " " << "no"<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

