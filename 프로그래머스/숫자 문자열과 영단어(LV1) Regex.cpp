#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

int solution(string s) {
    map<string, string> m;
    string answer = "";
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            answer += s[i];
        else
        {
            if (m.find(s.substr(i,3))!=m.end())
            {
                answer += m[s.substr(i, 3)];
                i += 2;
            }
            else if (m.find(s.substr(i, 4)) != m.end())
            {
                answer += m[s.substr(i, 4)];
                i += 3;
            }
            else if (m.find(s.substr(i, 5)) != m.end())
            {
                answer += m[s.substr(i, 5)];
                i += 4;
            }
        }
    }
    return stoi(answer);
}
/*
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
*/