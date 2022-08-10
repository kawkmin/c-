#include <iostream>

using namespace std;

int N, r, c;
int result;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << result;
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        Z(y, x, size / 2);
        Z(y, x + size / 2, size / 2);
        Z(y + size / 2, x, size / 2);
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        result += size * size;
    }
}
int main()
{
    cin >> N >> r >> c;
    Z(0, 0, (int)pow(2,N));
}