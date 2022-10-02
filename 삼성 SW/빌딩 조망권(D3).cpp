#include<iostream>

using namespace std;

int main()
{
    int test_case;
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int N, a[1001], cnt = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i < N - 2; i++)
        {
            if (a[i] - 1 >= a[i - 1] && a[i] - 1 >= a[i - 2] && a[i] - 1 >= a[i + 1] && a[i] - 1 >= a[i + 2])
            {
                int MIN = 256;
                int x = min(MIN, min(a[i] - a[i - 1], min(a[i] - a[i - 2], min(a[i] - a[i + 1], a[i] - a[i + 2]))));
                cnt += x;
            }
        }
        cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}