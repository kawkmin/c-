#include<iostream>

using namespace std;
int N, visit[21][21];
char map[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int maxx = 0, maxy = 0;


void dfs(int y, int x)
{
    maxx = max(maxx, x);
    maxy = max(maxy, y);
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ay = y + dy[i];
        int ax = x + dx[i];
        if (ay >= 0 && ax >= 0 && ax < N && ay < N && !visit[ay][ax] && map[ay][ax] == '#')
            dfs(ay, ax);
    }

}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        maxx = 0;
        maxy = 0;
        bool b = 1;
        bool bb = 1;
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visit[i][j] = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == '#' && !visit[i][j])
                {
                    if (!b)
                    {
                        bb = 0;
                        break;
                    }
                    b = 0;
                    dfs(i, j);
                    if (maxy - i == maxx - j)
                    {
                        for (int k = i; k <= maxy; k++)
                        {
                            for (int z = j; z <= maxx; z++)
                            {
                                if (map[k][z] == '.')
                                    bb = 0;
                            }
                        }
                    }
                    else
                        bb = 0;
                }
                if (!bb)
                    break;
            }
            if (!bb)
                break;
        }
        if (bb)
            cout << "#" << test_case << " yes" << "\n";
        else
            cout << "#" << test_case << " no" << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}