#include <string>
#include <vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {  
    vector<int> answer;
    unordered_map<string,string> map1;
    map<string, int>map2;
    for (int i = 0; i < records.size(); i++)
    {
        if (records[i].substr(11, 2) == "IN")
        {
            map1[records[i].substr(7, 4)] = records[i].substr(0, 5);
        }
        else
        {
            int x = stoi(records[i].substr(0, 2)); //substr은 새로운 문자열을 만들어서 시간복잡도가 좋지 않다.
            int y = stoi(records[i].substr(3, 2));
            string s = map1[records[i].substr(7, 4)];
            int hour = x - stoi(s.substr(0, 2));
            int minute = y - stoi(s.substr(3, 2));
            map1.erase(records[i].substr(7, 4));
            if (minute < 0)
            {
                hour--;
                minute += 60;
            }
            int time = hour * 60 + minute;
            map2[records[i].substr(7, 4)] += time;
        }
    }
    for (auto a : map1)
    {
        int hour = 23 - stoi(a.second.substr(0, 2));
        int minute = 59 - stoi(a.second.substr(3, 2));
        int time = hour * 60 + minute;
        map2[a.first] += time;
    }
    for (auto a : map2)
    {
        int result = fees[1];
        if (a.second > fees[0])
        {
            a.second -= fees[0];
            while (a.second > 0)
            {
                result += fees[3];
                a.second -= fees[2];
            }
        }
        answer.push_back(result);
    }
    return answer;
}