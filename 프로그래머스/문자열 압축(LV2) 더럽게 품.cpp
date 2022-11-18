#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

int solution(string s) {
    int answer = 1001;
    for (int i = 1; i <= s.length() / 2; i++)
    {
        int cnt = 0;
        for (int j = 0; j < s.length(); j += i)
        {
            string temp = s.substr(j, i);
            cnt += temp.length();
            bool b = false;
            int cnt2 = 1;
            int x = 10;
            for (int k = j + i; k < s.length(); k += i)
            {
                string temp2 = s.substr(k, i);
                if (temp == temp2)
                {
                    j += i;
                    if (!b)
                    {
                        b = true;
                        cnt++;
                        cnt2++;
                    }
                    else
                    {
                        cnt2++;
                        if (cnt2 == x)
                        {
                            cnt++;
                            x *= 10;
                        }
                        continue;
                    }
                }
                else
                    break;
            }
        }
        answer = min(answer, cnt);

    }
    if (answer == 1001)
        return s.length();
    return answer;
}