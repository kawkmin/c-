#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0;i < s.length();i++)
	{
		if (i + 1 < s.length()) 
		{
			string xs;
			xs += s[i];
			xs += s[i + 1];
			if (xs == "dz"&&i+2<s.length())
			{
				xs += s[i + 2];
				if (xs == "dz=")
					i+=2;
				
			}
			else if (xs == "lj" || xs == "c=" || xs == "c-" || xs == "d-" || xs == "nj" || xs == "s=" || xs == "z=")
			{
				i++;
			}
		}
		cnt++;
	}
	cout << cnt;

}