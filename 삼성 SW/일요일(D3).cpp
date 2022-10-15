#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	string days[8] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int result[8] = { 7,6,5,4,3,2,1 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;
		int index;
		for (int i = 0; i < 7; i++)
			if (s == days[i])
				index = i;
		cout << "#" << test_case << " " << result[index] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}