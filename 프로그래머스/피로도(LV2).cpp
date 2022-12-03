#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;
int visit[8] = { 0, };
int answer = 0;

void dfs(int tire, int cnt)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (!visit[i])
        {
            if (tire >= v[i][0])
            {
                visit[i] = 1;
                dfs(tire - v[i][1], cnt + 1);
                visit[i] = 0;
            }
        }
    }
    answer = max(answer, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    dfs(k, 0);
    return answer;
}
