#include<vector>
#include<queue>
using namespace std;
int visit[12345][12345] = { 0, };

int solution(vector<vector<int>> maps)
{
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    queue<pair<pair<int, int>, int>> q;
    int answer = 0;

    q.push({ {0,0},1 });
    while (!q.empty())
    {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int value = q.front().second;
        if (x == maps[0].size() - 1 && y == maps.size() - 1) {
            answer = value;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 0 && ay >= 0 && ax < maps[0].size() && ay < maps.size() && !visit[ay][ax] && maps[ay][ax])
            {
                visit[ay][ax] = 1;
                q.push({ {ay,ax},value + 1 });
            }
        }
    }
    if (answer == 0)
        return -1;
    return answer;
}