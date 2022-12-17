#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int total_weight = 0;
    int index = 0;

    while (1)
    {
        if (index == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        answer++;

        if (q.size() == bridge_length)
        {
            total_weight -= q.front();
            q.pop();
        }

        if (truck_weights[index] + total_weight <= weight)
        {
            q.push(truck_weights[index]);
            total_weight += truck_weights[index];
            index++;
        }
        else
        {
            q.push(0);
        }
    }

    return answer;
}