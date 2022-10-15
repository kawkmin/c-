#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        string MAX = s;
        string MIN = s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                string temp = s;
                swap(temp[i], temp[j]);
                if (temp[0] != '0')
                {
                    MAX = max(temp, MAX);
                    MIN = min(temp, MIN);
                }
            }
        }
        cout << "#" << test_case << " " << MIN << " " << MAX << "\n";
    }
    return 0;
}