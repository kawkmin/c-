#include <string.h>
#include <vector>
#include<cmath>
#include<iostream>
using namespace std;
int visit[101] = { 0, };
int cnt = 0;

void dfs(vector<int> v[], int x)
{
    visit[x] = 1;
    cnt++;
    for (int i = 0; i < v[x].size(); i++)
    {
        if(!visit[v[x][i]])
           dfs(v, v[x][i]);
    }
}

int solution(int n, vector<vector<int>> wires) { //그래프를 미완성된 상태로 비교를 하였음.
    int answer = 101;
    for (int j = 0; j < wires.size()-1; j++)
    {
        memset(visit, 0, sizeof(visit));
        cnt = 0;
        vector<int> v2[101];
        for (int i = 0; i < j; i++)
        {
            v2[wires[i][0]].push_back(wires[i][1]); 
            v2[wires[i][1]].push_back(wires[i][0]);
        }
        dfs(v2, wires[0][0]);
        memset(visit, 0, sizeof(visit));
        int temp = cnt;
        cnt = 0;

        vector<int> v[101];
        for (int i = j+1; i < wires.size(); i++)
        {
            v[wires[i][0]].push_back(wires[i][1]);
            v[wires[i][1]].push_back(wires[i][0]);

        }
        dfs(v, wires[j+1][0]);
        answer = min(answer, abs(cnt - temp));
    }
    return answer;
}

int main()
{
    vector<int> v1(2);
    v1[0] = 1; v1[1] = 2;
    vector<int> v2(2);
    v2[0] = 2; v2[1] = 7;
    vector<int> v3(2);
    v3[0] = 3; v3[1] = 7;

    vector<int> v4(2);
    v4[0] = 3; v4[1] = 4;
    vector<int> v5(2);
    v5[0] = 4; v5[1] = 5;
    vector<int> v6(2);
    v6[0] = 6; v6[1] = 7;

    vector<vector<int>> v7;
    v7.push_back(v1);
    v7.push_back(v2);
    v7.push_back(v3);
    v7.push_back(v4);
    v7.push_back(v5);
    v7.push_back(v6);
    solution(4, v7);
}