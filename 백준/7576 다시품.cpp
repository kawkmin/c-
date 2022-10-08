#include <iostream>
#include<queue>

using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M, box[1001][1001];
int visit[1001][1001];

int main()
{
    queue<pair<pair<int, int>, int>> q;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> box[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 1)
            {
                q.push({ {i,j},0 });
            }
        }
    }
    int day = 0;
    while (!q.empty())
    {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int d = q.front().second + 1;
        day = max(d, day); //queue는 선입선출이라 어차피 마지막이 제일 큰 값이라서 max 필요없
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 0 && ay >= 0 && ax < M && ay < N && box[ay][ax] == 0)
            {
                box[ay][ax] = 1;
                q.push({ {ay,ax},d });
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day - 1;
}