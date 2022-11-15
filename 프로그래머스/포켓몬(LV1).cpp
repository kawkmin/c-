#include <vector>
#include<map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!m[nums[i]]) {
            m[nums[i]] = 1;
            answer++;
        }
        if (answer == nums.size() / 2)
            break;
    }
    return answer;
}