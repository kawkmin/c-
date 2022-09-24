#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int result = 0;
	string num;
	bool b = false;

	for (int i = 0; i <= s.size(); i++)
	{

		if (s[i] == '-' || s[i] == '+' || i == s.size())
		{
			if (b)
			{
				result -= stoi(num);
				num = "";
			}
			else
			{
				result += stoi(num);
				num = "";
			}
		}
		else
			num += s[i];

		if (s[i] == '-')
			b = true;

	}

	cout << result;
}
