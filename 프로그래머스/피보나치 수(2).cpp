#include <string>
#include <vector>

using namespace std;

long long dp[100001];

long long dy(int a) {
    if (dp[a] || a == 0)
        return dp[a];
    else
        return dp[a] = dy(a - 1) + dy(a - 2) % 1234567;
}

int solution(int n) {
    long long answer = 0;
    dp[0] = 0;
    dp[1] = 1;
    answer = (dy(n - 1) + dy(n - 2)) % 1234567;
    return answer;
}