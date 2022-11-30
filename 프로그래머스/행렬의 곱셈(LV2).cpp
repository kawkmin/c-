﻿#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int x = 0;
            for (int k = 0; k < arr2.size(); k++)
            {
                x += arr1[i][k] * arr2[k][j];
            }
            v.push_back(x);
        }
        answer.push_back(v);
    }
    return answer;
}