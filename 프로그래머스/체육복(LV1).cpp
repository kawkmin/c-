#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(31, 1);
    v[0] = 0;
    v[n + 1] = 0;
    for (int i = 0; i < lost.size(); i++)
    {
        v[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++)
        v[reserve[i]]++;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            if (v[i - 1] == 2)
            {
                v[i - 1] = 1;
                v[i] = 1;
            }
            else if (v[i + 1] == 2) {
                v[i + 1] = 1;
                v[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (v[i] >= 1)
            answer++;
    return answer;
}