#include <iostream>
using namespace std;

int main() 
{
    int N = 0, M = 0, x = 0, y = 0;
    int a = 1001, b = 1001;
    cin >> N >> M;

    while (M--) 
    {
        cin >> x >> y;
        a = min(a, x);
        b = min(b, y);
    }
    cout << min((N / 6 + 1) * a, min(N / 6 * a + N % 6 * b, N * b)) << '\n';
}