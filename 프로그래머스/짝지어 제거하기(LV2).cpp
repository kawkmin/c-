#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (st.size()!=0&&s[i] == st.top())
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.size() == 0)
        return 1;
    return 0;
}

//string str; 재귀 시간초과
//void pairdel()
//{
//    if (str.length() < 2)
//        return;
//    for (int i = 0; i < str.length()-1; i++)
//    {
//        if (str[i] == str[i + 1])
//        {
//            str.erase(i, 2);
//            return pairdel();
//        }
//    }
//}
//
//int solution(string s)
//{
//    str = s;
//    pairdel();
//    if (str.size() == 0)
//        return 1;
//    return 0;
//}