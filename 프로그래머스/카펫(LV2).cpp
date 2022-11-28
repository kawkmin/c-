#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= brown; i++)
    {
        for (int j = 1; j <= brown; j++)
        {
            if ((i - 2) * (j - 2) == yellow)
            {
                if ((i * 2) + (j * 2) - 4 == brown)
                {
                    answer.push_back(j);
                    answer.push_back(i);
                    return answer;
                }
            }
        }
    }
    return answer;
}