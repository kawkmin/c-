#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<iostream>
using namespace std;
map<string, int> m;
bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
map<string, int> dic;
vector<pair<string, int>> sorted;
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0;i<orders.size();i++)
    {
        map <string,int> mc;
        sort(orders[i].begin(), orders[i].end());
        do{
            string s="";
            for(int j=0;j<orders[i].length();j++)
            {
                s+=orders[i][j];
                for(int co=0;co<course.size();co++)
                {
                    if(s.length()==course[co])
                    {
                        string temp=s;
                        sort(temp.begin(),temp.end());
                        if(!mc[temp])
                        {
                            mc[temp]=1;
                            if(m[temp])
                                m[temp]++;
                            else
                                m[temp]=1;
                        }
                    }
                }
            }          
        }while(next_permutation(orders[i].begin(),orders[i].end())); 
    }

    for (auto& order : m)
        if (order.second > 1)
            sorted.push_back(make_pair(order.first, order.second));
    sort(sorted.begin(), sorted.end(), cmp);

    for (int i = 0; i < course.size(); i++) {
        int max = 0;
        for (int j = 0; j < sorted.size(); j++) {
            if (sorted[j].first.length() != course[i]) //글자 수가 작은게 무조건 맨 위에 있음 2글자 순 큰값들 3글자 순 --- 4글자 순 ---- 이런식
                continue;
            else if (max == 0) {
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if (max == sorted[j].second)
                answer.push_back(sorted[j].first);
            else
                break;
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> v(6);
    v[0] = "ABCFG";
    v[1] = "AC";
    v[2] = "CDE";
    v[3] = "ACDE";
    v[4] = "BCFG";
    v[5] = "ACDEH";
    vector<int> v2(3);
    v2[0] = 2;
    v2[1] = 3;
    v2[2] = 4;
    solution(v, v2);
    for (auto a : sorted)
        if(a.second>1)
            cout << a.first << " " << a.second<<'\n';
  
}