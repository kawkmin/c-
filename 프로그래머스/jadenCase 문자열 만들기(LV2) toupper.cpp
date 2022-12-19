﻿#include <string>
#include <vector>

using namespace std;
//toupper(char c) = 대문자로만 반환 tolower

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 || s[i - 1] == ' ')
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                answer += s[i] + 'A' - 'a';
            else
                answer += s[i];
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                answer += s[i] - ('A' - 'a');
            else
                answer += s[i];
        }
    }
    return answer;
}