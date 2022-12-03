#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    vector<vector<int>> dp(board.size(), vector<int>(board[0].size()));
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0 || i == 0 || j == 0)
            {
                dp[i][j] = board[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            answer = max(answer, dp[i][j]);
        }
    }

    return answer * answer;
}