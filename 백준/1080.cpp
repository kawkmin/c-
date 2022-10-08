#include <iostream>

using namespace std;
int N, M;
char a[51][51], b[51][51];
int cnt = 0;

void swap(int x, int y)
{
    cnt += 1;
    for (int i = y; i < y+3; i++)
    {
        for (int j = x; j < x+3; j++)
        {
            if (a[i][j] == '0')
                a[i][j] = '1';
            else
                a[i][j] = '0';
        }
    }
}

int main() 
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> b[i][j];
    
    for (int i = 0; i < N-2; i++)
    {
        for (int j = 0; j < M-2; j++)
        {
            if (a[i][j] != b[i][j])
                swap(j, i);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;
}