#include <iostream>
#include <algorithm>

using namespace std;
long long a[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    long long MAX = 0;
    for (int i = 0; i < n; i++)
    {
        if (MAX < a[i] * (n - i))
            MAX = a[i] * (n - i);

    }
    cout << MAX;
}