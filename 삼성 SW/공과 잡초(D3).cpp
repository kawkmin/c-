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
        int cnt = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                i++;
                cnt++;
            }
            else if (s[i] == '|')
                if (s[i + 1] == ')')
                    cnt++;
        }
       cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}