//https://www.acmicpc.net/problem/1912

#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n;
	int dp[100001];
	int max_sum;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dp[i];
	}
	max_sum = dp[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		if (dp[i] > max_sum)
			max_sum = dp[i];
	}

	cout << max_sum;

	return 0;
}