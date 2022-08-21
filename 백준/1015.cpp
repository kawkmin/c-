#include <iostream>
using namespace std;

int main()
{
    int N, a[51], P[51],min=0;
    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> a[i];
    
    for (int i = 0; i < N; i++) 
    {
        int m = 1001;
        for (int j = 0; j < N; j++) 
        {
            if (a[j] < m) 
            {
                m = a[j];
                min = j;
            }
        }
        P[min] = i;
        a[min] = 1001;
    }
    for (int i = 0; i < N; i++)
        cout << P[i] << " ";
   
}
