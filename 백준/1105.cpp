#include<iostream>
#include<string>
using namespace std;

int main()
{
	int L, R, cnt = 0;
	cin >> L >> R;
	string sl = to_string(L);
	string sr = to_string(R);
	if (sl.length() < sr.length())
		cout << cnt;
	else
	{
		for (int i = 0; i < sl.length(); i++)
		{
			if (sl[i] == sr[i])
			{
				if (sl[i] == '8')
					cnt++;
			}
			else
				break;

		}
		cout << cnt;
	}
}