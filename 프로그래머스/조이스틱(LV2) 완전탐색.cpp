#include <string>
#include <vector>
#include<iostream>
using namespace std;
string tempname;
int answer = 1234567;

void dfs(string str, int index,int cnt)
{
    if (str == tempname)
    {
        answer = min(cnt, answer);
        return;
    }
    int cnt1 = 0;
    char tempc1 = 'A';
    for (int i = 0; i < 'Z' - 'A'; i++)
    {
        if (tempc1 == tempname[index])
            break;
        cnt1++;
        tempc1++;
        if (tempc1 > 'Z')
            tempc1 = 'A';
    }

    int cnt2 = 0;
    char tempc2 = 'A';
    for (int i = 0; i < 'Z' - 'A'; i++)
    {
        if (tempc2 == tempname[index])
            break;
        cnt2++;
        tempc2--;
        if (tempc2 < 'A')
            tempc2 = 'Z';
    }
    
    cnt+=min(cnt1,cnt2);
    str[index] = tempname[index];
    if (str == tempname)
    {
        answer = min(cnt, answer);
        return;
    }
    int tempindex1 = index;
    int tempindex2 = index;
    int visit[21] = { 0, };
    for (int i = 1; i <= str.length(); i++)
    {
        tempindex1++;
        if (tempindex1 > str.length() - 1)
            tempindex1 = 0;
        tempindex2--;
        if (tempindex2 < 0)
            tempindex2 = str.length() - 1;        
        
        if (!visit[tempindex1])
        {
            if (str[tempindex1] != tempname[tempindex1])
            {
                visit[tempindex1] = 1;
                dfs(str, tempindex1, cnt + i);
            }
        }
        if (!visit[tempindex2] && str[tempindex2] != tempname[tempindex2])
        {
            visit[tempindex2] = 1;
            dfs(str, tempindex2, cnt + i);
        }
    }
}

int solution(string name) {
    tempname = name;
    string str = "";
    for (int i = 0; i < name.length(); i++)
    {
        str += 'A';
    }
    dfs(str, 0, 0);
    return answer;
}

int main() 
{
    cout << solution("ABABAAAAABA");
}