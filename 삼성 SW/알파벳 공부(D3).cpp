#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	if (s[0] == 'a')
	{
		cnt++;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i]==s[i-1]+1)
				cnt++;
			else
				break;
		}
	}
	cout << cnt;
}