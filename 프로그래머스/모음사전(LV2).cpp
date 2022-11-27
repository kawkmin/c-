#include <string>
#include <vector>
#include<map>
using namespace std;
char arr[5] = { 'A','E','I','O','U' };
int place = 1;
map<string, int> m;
void dfs(string str, int dep)
{
    if (dep == 5)
        return;
    for (int i = 0; i < 5; i++)
    {
        string s = str;
        s += arr[i];
        m[s] = place++;
        dfs(s, dep + 1);
    }
}

int solution(string word) 
{
    dfs("", 0);   
    return m[word];
}