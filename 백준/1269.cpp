#include <iostream>
#include<map>
using namespace std;

map <int, int> m;
int A, B, ans;
int a[200001];
int b[200001];
int main() 
{
    cin >> A >> B;
    for (int i = 0; i < A; i++) 
        cin >> a[i];
    for (int i = 0; i < B; i++)
        cin >> b[i];

    for (int i = 0; i < A; i++) 
        m[a[i]]++;

    for (int i = 0; i < B; i++) 
        if (m[b[i]]) 
            ans++;

    cout << A + B - ans * 2;
}