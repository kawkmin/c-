#include<iostream>
#include<string>
using namespace std;


int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 'A')
			continue;
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			for (int j = 0; j < 13; j++)
			{
				s[i]++;
				if (s[i] > 'Z')
					s[i] = 'A';
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			for (int j = 0; j < 13; j++)
			{
				s[i]++;
				if (s[i] > 'z')
					s[i] = 'a';
			}
		}
	}
	cout << s;
}