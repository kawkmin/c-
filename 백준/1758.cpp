#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];

int main()
{
    int n;
    long long res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int idx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int a = (arr[idx] - i > 0) ? arr[idx] - i : 0;
        idx++;
        res += a;
    }
    cout << res;
}