#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>  arr1 = { 1,2,3,4,5 };
    vector<int>  arr2 = { 2,1,2,3,2,4,2,5 };
    vector<int>  arr3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        int index = i % 5;
        if (arr1[index] == answers[i])
            sum1++;
    }
    for (int i = 0; i < answers.size(); i++)
    {
        int index = i % 8;
        if (arr2[index] == answers[i])
            sum2++;
    }
    for (int i = 0; i < answers.size(); i++)
    {
        int index = i % 10;
        if (arr3[index] == answers[i])
            sum3++;
    }

    int MAX = max(max(sum1, sum2), sum3);
    if (sum1 == MAX)
        answer.push_back(1);
    if (sum2 == MAX)
        answer.push_back(2);
    if (sum3 == MAX)
        answer.push_back(3);
    return answer;
}