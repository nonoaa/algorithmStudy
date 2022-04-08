//https://www.acmicpc.net/problem/14889

#include <algorithm>
#include <iostream>

using namespace std;

int s[20][20];
int n;
int team[20];
int diff_min = 2147483647;

void dfs(int index, int cnt)
{
	if (cnt == n / 2)
	{
		int start = 0, link = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (team[i] == 0 && team[j] == 0 && i != j)
					start += s[i][j];
				if (team[i] == 1 && team[j] == 1 && i != j)
					link += s[i][j];
			}
		}

		diff_min = min(diff_min, abs(start - link));
	}

	if (index >= n)
	{
		return;
	}

	team[index] = 1;
	dfs(index + 1, cnt + 1);
	team[index] = 0;
	dfs(index + 1, cnt);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	dfs(0, 0);

	cout << diff_min;
	return 0;
}