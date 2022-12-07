#include <string>
#include <vector>
#include<queue>
using namespace std;
vector<int> v[20000];
int visit[20000] = { 0, };
int MAX = 0;
int answer = 0;

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++)
    {
        v[edge[i][1]].push_back(edge[i][0]);
        v[edge[i][0]].push_back(edge[i][1]);
    }
    queue<pair<int, int>> q;
    q.push({ 1,0 });
    while (!q.empty())
    {
        int x = q.front().first;
        int dep = q.front().second;
        visit[x] = 1;
        if (dep > MAX)
        {
            MAX = dep;
            answer = 1;
        }
        else if (dep == MAX)
        {
            answer++;
        }
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            if (!visit[v[x][i]])
            {
                q.push({ v[x][i],dep + 1 });
                visit[v[x][i]] = 1;
            }
        }
    }
    return answer;
}