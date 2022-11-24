#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    string tempName = "";
    int arr[21] = { 0, };
    for (int i = 0; i < name.length(); i++)
    {
        tempName += 'A';
        if (name[i] == 'A')
            arr[i] = 1;
    }
    int index = 0;
    while (tempName!=name)
    {
        char temp1 = 'A';
        int cnt1 = 0;
        for (int i = 0; i < 'Z' - 'A'; i++)
        {
            if (temp1 > 'Z')
                temp1 = 'A';
            if (temp1 == name[index])
            {
                break;
            }
            temp1++;
            cnt1++;
        }

        char temp2 = 'A';
        int cnt2 = 0;
        for (int i = 0; i < 'Z' - 'A'; i++)
        {
            if (temp2 < 'A')
                temp2 = 'Z';
            if (temp2 == name[index])
                break;
            temp2--;
            cnt2++;
        }
        answer += min(cnt1, cnt2);
        tempName[index] = name[index];
        arr[index] = 1;

        int tempindex1 = index;
        int tempindex2 = index;
        for (int i = 1; i <= name.length(); i++)
        {
            tempindex1--;
            if (tempindex1 < 0)
                tempindex1 = name.length() - 1;

            tempindex2++;
            if (tempindex2 > name.length() - 1)
                tempindex2 = 0;

            if (arr[tempindex2] == 0)
            {
                answer += i;
                index = tempindex2;
                break;
            }
            if (arr[tempindex1] == 0)
            {
                answer += i;
                index = tempindex1;
                break;
            }
        }
    }
    return answer;
}

int main() 
{
    cout << solution("BBBBAAAABA");
}