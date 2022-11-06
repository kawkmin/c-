#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
int era[10000000] = { 0, };
int visit[10000000] = { 0, };
int answer = 0;

vector<int>v;
set<int> se;
void eratos()
{
    era[1] = 1;
    era[0] = 1;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (era[i] == 1) continue;
        for (int j = i * i; j < 10000000; j += i)
        {
            era[j] = 1;
        }
    }
}
void dfs(int x)
{
    if (x != 0 && era[x] == 0)
    {
        se.insert(x);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (visit[i]) continue;
        visit[i] = 1;
        dfs(x * 10 + v[i]);
        visit[i] = 0;
    }
}

int solution(string numbers)
{
    eratos();
    for (int i = 0; i < numbers.length(); i++)
    {
        v.push_back(numbers[i] - '0');
    }
    dfs(0);
    answer = se.size();
    return answer;
}