#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> q2;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({ i,priorities[i] });
        q2.push(priorities[i]);
    }
    while (!q.empty())
    {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (value == q2.top())
        {
            q2.pop();
            answer++;
            if (index == location)
                break;
        }
        else
            q.push({ index,value });
    }

    return answer;
}