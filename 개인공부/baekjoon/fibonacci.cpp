//https://www.acmicpc.net/problem/1003

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[t];
    pair<int, int> dp[41];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    
    for (int i = 2; i < 41; i++)
    {
        dp[i].first = dp[i-2].first + dp[i-1].first;
        dp[i].second = dp[i-2].second + dp[i-1].second;
    }
    
    for(int i = 0; i < t; i++)
    {
        cout << dp[arr[i]].first << " " << dp[arr[i]].second << "\n";
    }
    return (0);
}
