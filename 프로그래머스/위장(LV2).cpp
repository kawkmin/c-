#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++)
    {
        string name = clothes[i][0];
        string categori = clothes[i][1];
        if (m.find(categori) != m.end())
        {
            m[categori]++;
        }
        else
            m[categori] = 2;
    }
    int mux = 1;
    for (auto s : m)
    {
        mux *= s.second;
    }
    if (m.size() == 1)
        return clothes.size();
    answer += mux - 1;
    return answer;
}