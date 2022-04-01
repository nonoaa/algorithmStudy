//https://programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<vector<int>> dp(board.size(), vector <int>(board[0].size(), 0));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dp[i][j] = board[i][j];
            if (dp[i][j] == 1)
                answer = 1;
        }
    }

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (dp[i][j] != 0)
            {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                answer = max(answer, dp[i][j] * dp[i][j]);
            }
        }
    }

    return answer;
}