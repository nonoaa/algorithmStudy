//https://www.acmicpc.net/problem/1149

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[1000][3];
    for (int i = 0; i < n; i++)
    {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i-1][1] + dp[i][0], dp[i-1][2] + dp[i][0]);
        dp[i][1] = min(dp[i-1][0] + dp[i][1], dp[i-1][2] + dp[i][1]);
        dp[i][2] = min(dp[i-1][0] + dp[i][2], dp[i-1][1] + dp[i][2]);
    }
    
    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    return (0);
}

