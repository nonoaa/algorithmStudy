//https://www.acmicpc.net/problem/2579

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	int stair[300];
	int dp[300];

	for (int i = 0; i < n; i++)
	{
		cin >> stair[i];
		if (i == 0)
			dp[i] = stair[i];
		else if (i == 1)
			dp[i] = stair[i];
	}

	dp[0] = stair[0];
	if (n >= 2)
		dp[1] = stair[0] + stair[1];
	if (n >= 3)
		dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], stair[i] + stair[i - 1] + dp[i - 3]);
	}

	cout << dp[n - 1];

	return 0;
}