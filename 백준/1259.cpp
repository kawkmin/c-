#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (1)
	{
		bool b = true;
		cin >> s;
		if (s == "0")
			break;

		for (int i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - 1 - i])
			{
				b = false;
				break;
			}
		}

		if (b)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}