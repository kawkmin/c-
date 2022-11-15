#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    int array1[10] = { 0, };
    int array2[10] = { 0, };
    int array3[10] = { 0, };
    for (int i = 0; i < X.length(); i++)
        array1[X[i] - '0'] += 1;
    for (int i = 0; i < Y.length(); i++)
        array2[Y[i] - '0'] += 1;
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        int MIN = min(array1[i], array2[i]);
        for (int j = 0; j < MIN; j++)
            v.push_back(i);
    }
    if (v.size() == 0)
        return "-1";

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        answer += to_string(v[i]);
    if (answer[0] == '0')
        return "0";
    return answer;
}