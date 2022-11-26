#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int visit[21] = { 0, };
int answer = 0;
int t;

vector<int> v;
void dfs(int cnt, int dep)
{
    if (dep == v.size())
    {
        if (cnt == t)
        {
            answer++;
        }
        return;
    }
    dfs(cnt + v[dep], dep + 1);
    dfs(cnt - v[dep], dep + 1);
}

int solution(vector<int> numbers, int target) {
    v = numbers;
    t = target;
    dfs(0, 0);
    return answer;
}