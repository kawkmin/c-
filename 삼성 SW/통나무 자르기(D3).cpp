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
        int a;
        cin >> a;
        if (a % 2 == 1)
            cout << "#" << test_case << " " << "Bob" << "\n";
        else
            cout << "#" << test_case << " " << "Alice" << "\n";
    }
    return 0;
}