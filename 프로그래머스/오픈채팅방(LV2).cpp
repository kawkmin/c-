#include <string>
#include <vector>
#include<sstream>
#include<map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> result;
    map<string, string> map1;

    for (int i = 0; i < record.size(); i++)
    {
        string cal, id, name;
        stringstream ss(record[i]);
        if (record[i][0] == 'L')
        {
            ss >> cal >> id;
            result.push_back({ id,"L" });
        }
        else
        {
            ss >> cal >> id >> name;
            map1[id] = name;
        }
        if (cal == "Enter")
        {
            result.push_back({ id,"E" });
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        string s = map1[result[i].first];
        if (result[i].second == "E")
            s += "님이 들어왔습니다.";
        else
            s += "님이 나갔습니다.";
        answer.push_back(s);
    }
    return answer;
}
