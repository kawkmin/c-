#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int temp = -30001;
    for (int i = 0; i < routes.size(); i++)
    {
        if (temp < routes[i][0])
        {
            answer++;
            temp = routes[i][1];
        }
    }
    return answer;
}