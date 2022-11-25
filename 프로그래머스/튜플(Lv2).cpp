#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(vector<string> s1, vector<string> s2)
{
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<string>> temps;
    int visit[100001] = { 0, };
    int ind = 0;
    int index = 2;
    for (int i = 2; i < s.length() - 1; i++)
    {
        if (s[i] == '}')
        {
            string ss = s.substr(index, i - index);
            vector<string> v;
            string cntss="";
            for (int j = 0; j < ss.size(); j++)
            {
                if (ss[j] == ',')
                {
                    v.push_back(cntss);
                    cntss = "";
                }
                else
                {
                    cntss += ss[j];
                    if (j == ss.size() - 1)
                        v.push_back(cntss);
                }
            }
            temps.push_back(v);
            index = i + 3;
        }
    }
    sort(temps.begin(), temps.end(), cmp);
    for (int i = 0; i < temps.size(); i++)
    {
        for (int j = 0; j < temps[i].size(); j++)
        {
            if (!visit[stoi(temps[i][j])])
            {
                visit[stoi(temps[i][j])] = 1;
                answer.push_back(stoi(temps[i][j]));
            }
        }
    }
    return answer;
}

