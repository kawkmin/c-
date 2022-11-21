#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		string s = to_string(i);
		int cnt = 0;
		for (int j = 0;j < s.length();j++)
		{
			if (s[j] == '3' || s[j] == '6' || s[j] == '9')
				cnt++;
		}
		if (cnt)
		{
			for (int i = 0;i < cnt;i++)
				cout << '-';
			cout << " ";
		}
		else
			cout << s << " ";
	}

}