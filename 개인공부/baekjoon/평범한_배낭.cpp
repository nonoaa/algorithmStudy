#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> w(n + 1);
	vector<int> v(n + 1);
	vector<vector<int>> dp(n + 1,  vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
	return 0;
}