#include <iostream>
#include<cstring>
using namespace std;

int main()
{
	string s;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string S;
		int a;
		cin >> a >> s;

		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < a; j++)
			{
				S += s[i];
			}
		}
		cout << S<<"\n";
	}
}
