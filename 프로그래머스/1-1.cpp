#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int index = 0;
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            index = i;
            break;
        }
    }
    string strindex = to_string(index);
    answer = "�輭���� " + strindex + "�� �ִ�";
    return answer;
}