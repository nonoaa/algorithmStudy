//https://www.acmicpc.net/problem/2156

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> w(n + 1);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	dp[0] = 0;
	dp[1] = w[1];
	dp[2] = w[1] + w[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + w[i - 1] + w[i], max(dp[i - 2] + w[i], dp[i - 1]));
	}

	cout << dp[n];

	return 0;
}