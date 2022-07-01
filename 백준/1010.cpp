#include<iostream>

using namespace std;

int main() 
{
    int t,n, m;
    cin >> t;
    long long result = 1;
    for (int i = 0; i < t; i++) 
    {
        result = 1;
        cin >> n >> m;
        if (n > (m / 2))
            n = (m - n);

        for (int j = 0; j < n; j++)
            result *= (m - j);
        
        for (int k = 0; k < n; k++) 
            result /= (k + 1);
        
        cout << result << "\n";
    }
}