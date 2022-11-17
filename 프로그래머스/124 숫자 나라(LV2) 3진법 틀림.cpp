#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(int n) {
    char array[3] = { '4','1','2' };
    string answer = "";
    while (n)
    {
        answer = array[n % 3] + answer;
        if (n % 3 == 0)
            n = n / 3 - 1;
        else
            n /= 3;
    }
    return answer;
}