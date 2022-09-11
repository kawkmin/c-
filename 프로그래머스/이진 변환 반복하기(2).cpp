#include <string>
#include <vector>

using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    int cnt1 = 0, cnt2 = 0;
    while (1)
    {
        if (s == "1")
            break;
        cnt1++;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                cnt++;
        }
        cnt2 += cnt;
        int a = s.size() - cnt;
        s = "";
        while (a > 0)
        {
            s += to_string(a % 2);
            a /= 2;
        }
    }
    answer.push_back(cnt1);
    answer.push_back(cnt2);
    return answer;
}