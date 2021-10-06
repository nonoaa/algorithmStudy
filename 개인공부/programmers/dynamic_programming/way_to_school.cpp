//https://programmers.co.kr/learn/courses/30/lessons/42898?language=cpp

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for (int i = 0; i < puddles.size(); i++)
    {
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    for (int j = 0; j < m; j++)
    {
        if (dp[0][j] == -1)
            break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j] == -1)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (dp[i][j - 1] == -1)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    answer = dp[n - 1][m - 1];

    return answer;
}