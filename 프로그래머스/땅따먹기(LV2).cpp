﻿#include <iostream>
#include <vector>
using namespace std;
int dp[100001][4] = { 0, };

int solution(vector<vector<int> > land)
{
    int answer = 0;
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int MAX = 0;
            for (int k = 0; k < 4; k++)
            {
                if (k != j)
                {
                    MAX = max(MAX, dp[i - 1][k]);
                }
            }
            dp[i][j] = MAX + land[i][j];
        }
    }
    for (int k = 0; k < 4; k++)
    {
         answer = max(answer, dp[land.size()-1][k]);
    }
    return answer;
}