#include <string>
#include <vector>
#include<map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for (int i = 0; i < participant.size(); i++)
    {
        if (!m[participant[i]])
            m[participant[i]] = 1;
        else
            m[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++)
    {
        m[completion[i]]--;
    }
    for (auto a : m) {
        if (a.second >= 1)
        {
            for (int i = 0; i < a.second; i++)
                answer += a.first;
        }
    }
    return answer;
}