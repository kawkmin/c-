#include <iostream>
using namespace std;

int main() 
{
    int N, left;
    int ary[11] = { 0,};
    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> left;
        for (int j = 0; j < N; j++) 
        {
            if (left == 0 && ary[j] == 0) 
            {
                ary[j] = i + 1;
                break;
            }
            else if (ary[j] == 0)
            left--; 
        }
    }
    for (int i = 0; i < N; i++) 
    {
        cout << ary[i] << " ";
    }
}
