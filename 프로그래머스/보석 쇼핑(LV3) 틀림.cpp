#include <string>
#include <vector>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> se;
    unordered_map<string, int> map;
    for (int i = 0; i < gems.size(); i++)
        se.insert(gems[i]);
    int left = 0;
    int right = 0;
    int i;
    int a = 10000;
    while (true)
    {
        for (i = right; i < gems.size(); i++)
        {
            map[gems[i]]++;
            if (map.size() == se.size())
            {
                right = i;
                break;
            }
        }
        if (i == gems.size())
            break;
        for (i = left; i < gems.size(); i++)
        {
            if (map[gems[i]] == 1)
            {
                left = i;
                break;
            }
            else
                map[gems[i]]--;
        }
        if (right - left < a)
        {
            answer[0]=left + 1;
            answer[1]=right + 1;
            a = right - left;
        }
        map.erase(gems[left]);
        left++;
        right++;
    }
    return answer;
}
