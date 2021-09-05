//https://programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> dp(8);
    
    dp[0].insert(N);

    if (N == number)
        return 1;

    for (int r = 1; r < 8; r++)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (i + j + 1 != r)
                    continue;
                for (int x : dp[i])
                {
                    for (int y : dp[j])
                    {
                        dp[r].insert(x + y);
                        dp[r].insert(x - y);
                        dp[r].insert(x * y);
                        if (y != 0)
                            dp[r].insert(x / y);
                    }
                }
            }
        }
        int NN = N;
        for (int i = 0; i < r; i++)
        {
            NN = NN * 10 + N;
        }
        dp[r].insert(NN);

        if (dp[r].find(number) != dp[r].end())
        {
            return r + 1;
        }
    }

    return -1;
}