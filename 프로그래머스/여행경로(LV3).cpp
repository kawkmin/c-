#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int visit[10001] = { 0, };
vector<vector<string>> t;
vector<vector<string>> an;
vector<string> v;

void dfs(string s, int dep)
{
    if (dep == t.size())
    {
        an.push_back(v);
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i][0] == s && !visit[i])
        {
            visit[i] = 1;
            v.push_back(t[i][1]);
            dfs(t[i][1], dep + 1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    t = tickets;
    v.push_back("ICN");
    dfs("ICN", 0);
    sort(an.begin(), an.end());
    return an[0];
}