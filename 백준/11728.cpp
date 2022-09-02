#include <iostream>

using namespace std;

int A[1000001], B[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int N, M,n=0,m=0;
	cin >> N >> M;
    for (int i = 0; i < N; i++) 
        cin >> A[i];  
    for (int i = 0; i < M; i++) 
        cin >> B[i];
    while (n < N && m < M) 
    {
        if (A[n] <= B[m])
            cout << A[n++] << " ";
        else
            cout << B[m++] << " ";
    }
    while (n < N) 
        cout << A[n++] << " ";
    while (m < M)
        cout << B[m++] << " ";
}