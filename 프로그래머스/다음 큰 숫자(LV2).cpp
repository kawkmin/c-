#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int next_n = 0;
    int cntx = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            cntx++;
        n /= 2;
    }
    while (true)
    {
        next_n = answer + 1;
        answer = next_n;
        int cnty = 0;
        while (next_n > 0)
        {
            if (next_n % 2 == 1)
                cnty++;
            next_n /= 2;
        }
        if (cnty == cntx)
            return answer;
    }
}