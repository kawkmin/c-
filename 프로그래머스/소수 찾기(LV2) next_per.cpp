#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int era[10000000] = { 0, };
int visit[10000000] = { 0, };
int answer = 0;

vector<int>v;

void eratos()
{
    era[1] = 1;
    era[0] = 1;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (era[i] == 1) continue;
        for (int j = i * i; j < 10000000; j += i)
        {
            era[j] = 1;
        }
    }
}


int solution(string numbers)
{
    eratos();
    for (int i = 0; i < numbers.length(); i++)
    {
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());
    do {
        int x = 0;
        for (int i = 0; i < v.size(); i++)
        {
            x = x * 10 + v[i];
            if (era[x] == 0 && !visit[x])
            {
                visit[x] = 1;
                answer++;
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    return answer;
}