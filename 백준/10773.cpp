#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    int K, n;
    cin >> K;
    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        cin >> n;
        if (n != 0) 
            s.push(n);
        else 
            s.pop();
    }
    long long sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) 
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}