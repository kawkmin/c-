#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int state = 0;
    int left = 0;
    int right = 0;
    int value = 1;
    int index = n;
    int arr[1000][1000];
    while (index >= 1)
    {
        if (state == 0)
        {
            for (int i = 1; i <= index; i++)
            {
                arr[left][right] = value++;
                left++;
            }
            left--;
            index--;
            right++;
            state = 1;
        }
        if (state == 1)
        {
            for (int i = 1; i <= index; i++)
            {
                arr[left][right] = value++;
                right++;
            }
            right -= 2;
            left--;
            state = 2;
            index--;
        }
        if (state == 2)
        {
            for (int i = 1; i <= index; i++)
            {
                arr[left][right] = value++;
                left--;
                right--;
            }
            left += 2;
            right += 1;
            state = 0;
            index--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}