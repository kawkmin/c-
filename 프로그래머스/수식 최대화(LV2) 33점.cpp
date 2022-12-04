#include <string>
#include <vector>
#include<cmath>
#include<algorithm>
using namespace std;

char dc[3] = { '+','*','-' };
int visit[3] = { 0, };
long long answer = 0;

void dfs(int dep,string ex) //연산에서 뒤에값이 -일 때 계산 못함.
{
    if (dep == 3)
        answer = max(answer, abs(stoll(ex)));

    for (int i = 0; i < 3; i++)
    {
        if (!visit[i])
        {
            visit[i] = 1;
            string temp = ex;
            for (int j = 0; j < temp.size(); j++)
            {
                if (temp[j] == dc[i])
                {
                    string s1, s2;
                    int da, db;
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (temp[k] > '9' || temp[k] < '0'||k==0)
                        {
                            if (k == 0)
                            {
                                s1 = temp.substr(k, j - k);
                                da = k;
                            }
                            else
                            {
                                s1 = temp.substr(k + 1, j - k - 1);
                                da = k + 1;
                            }
                            break;
                        }
                    }
                    for (int k = j+1; k < temp.size(); k++)
                    {
                        if (temp[k] > '9' || temp[k] < '0'||k==temp.size()-1)
                        {
                            if (k == temp.size() - 1)
                            {
                                s2 = temp.substr(j + 1, k - j);
                                db = k;
                            }
                            else
                            {
                                s2 = temp.substr(j + 1, k - j - 1);
                                db = k - 1;
                            }
                            break;
                        }
                    }
                    long long x;
                    if (i == 0)
                        x = abs(stoll(s1) + stoll(s2));
                    else if (i == 1)
                        x = abs(stoll(s1) * stoll(s2));
                    else
                        x = abs(stoll(s1) - stoll(s2));
                    temp.erase(da, db-da+1);
                    temp.insert(da, to_string(x));
                    j = 0;
                }
            }
            dfs(dep + 1, temp);
            visit[i] = 0;
        }
    }
}

long long solution(string expression) {
    dfs(0, expression);
    return answer;
}
