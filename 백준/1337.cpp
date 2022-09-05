#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[51];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
    int ans = 4;
    for (int i = 0; i < N; i++)
    {
        int tmp = distance(A + i, lower_bound(A, A + N, A[i] + 5));
        ans = min(ans, 5 - tmp);
    }

    cout << ans;
}
