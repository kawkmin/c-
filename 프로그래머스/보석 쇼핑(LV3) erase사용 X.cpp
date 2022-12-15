#include <string>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {

    vector<int> answer;
    unordered_map<string, int> m;
    unordered_set<string> s;
    for (int i = 0; i < gems.size(); i++)
    {
        s.insert(gems[i]);
    }
    int x = 0;
    int MIN = 123456;
    for (int i = 0; i < gems.size(); i++)
    {
        m[gems[i]]++;
        
        if (m.size() == s.size())
        {
            while (m[gems[x]] > 1) 
            {
                m[gems[x]]--;
                x++;
            }

            if (MIN > i - x)
            {
                MIN = i - x;
                answer = { x+1,i + 1 };
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> v = { "DIA", "EM", "EM", "RUB", "DIA" };
    vector<int> v2 = solution(v);
}