#include<iostream>
#include<string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
		string map[51];
		for (int i = 0; i < N; i++)
			cin >> map[i];
		int index = 0, indexi;
		for (int i = 0; i < N; i++)
		{
			for (int j = M - 1; j >= 0; j--)
			{
				if (map[i][j] == '1')
				{
					index = j;
					indexi = i;
					break;
				}
			}
			if (index)
				break;
		}
		int minus = 55;
		int resultsum = 0;
		int sum = 0;
		for (int i = 0; i < 8; i++)
		{
			string temp = map[indexi].substr(index - minus, 7);
			int x;
			if (temp == "0001101")
				x = 0;
			else if (temp == "0011001")
				x = 1;
			else if (temp == "0010011")
				x = 2;
			else if (temp == "0111101")
				x = 3;
			else if (temp == "0100011")
				x = 4;
			else if (temp == "0110001")
				x = 5;
			else if (temp == "0101111")
				x = 6;
			else if (temp == "0111011")
				x = 7;
			else if (temp == "0110111")
				x = 8;
			else if (temp == "0001011")
				x = 9;
			if (i % 2 == 0 || i == 0)
				sum += x * 3;
			else
				sum += x;
			resultsum += x;
			minus -= 7;
		}
		if (sum % 10)
			cout << "#" << test_case << " " << 0 << "\n";
		else
			cout << "#" << test_case << " " << resultsum << "\n";
	}
	return 0;
}