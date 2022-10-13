#include<iostream>
#include<string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'x')
                cnt++;
        }
        cout << s << "\n";
        if (cnt <= 7)
            cout << "#" << test_case << " YES" << "\n";
        else
            cout << "#" << test_case << " NO" << "\n";

	}
	return 0;
}