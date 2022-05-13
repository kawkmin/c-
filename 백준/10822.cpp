#include <iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int result = 0, index = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i]==',')
		{			
			result+=stoi(s.substr(index, i ));
			index = i + 1;
		}
		if (i == s.size() - 1)
		{
			int x = i;
			for (int j = x; j > 0; j--)
			{
				if (s[j] == ',')
				{
					x = j;
					break;
				}
			}
			result += stoi(s.substr(x+1, s.size()-1));
		}
	}
	cout << result;
}
