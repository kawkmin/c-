#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visit[201] = { 0, };// 프로그래머스는 이거해야함 안해서 1시간날림
    queue<int> q;
    for (int t = 0; t < n; t++)
    {
        if (!visit[t])
        {
            visit[t] = 1;
            q.push(t);
            answer += 1;
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (!visit[i] && computers[x][i] == 1)
                {
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
    }
    return answer;
}