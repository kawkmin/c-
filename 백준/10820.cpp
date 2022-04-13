#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	while (getline(cin, s,'\n'))
	{
		int sma = 0, big = 0, num = 0, blank = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
				blank++;
			else if (s[i] <= 57&&s[i]>=48)
				num++;
			else if (s[i] <= 90&&s[i]>=65)
				big++;
			else if(s[i]<=122&&s[i]>=97)
				sma++;
		}
		cout << sma<<" "<<big<<" "<<num<<" "<<blank<<"\n";
	}
}