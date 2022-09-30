//https://www.acmicpc.net/problem/2096

#include <iostream>

using namespace std;

int main()
{
	int maxDp[3];
	int minDp[3];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int maxTemp[3];
		int minTemp[3];
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			maxTemp[j] = temp;
			minTemp[j] = temp;
			if (i == 0)
			{
				maxDp[j] = temp;
				minDp[j] = temp;
			}
			else
			{
				if (j == 0)
				{
					maxTemp[j] += max(maxDp[0], maxDp[1]);
					minTemp[j] += min(minDp[0], minDp[1]);
				}
				if (j == 1)
				{
					maxTemp[j] += max(max(maxDp[0], maxDp[1]), maxDp[2]);
					minTemp[j] += min(min(minDp[0], minDp[1]), minDp[2]);
				}
				if (j == 2)
				{
					maxTemp[j] += max(maxDp[1], maxDp[2]);
					minTemp[j] += min(minDp[1], minDp[2]);
				}
			}
		}
		for (int j = 0; j < 3; j++)
		{
			maxDp[j] = maxTemp[j];
			minDp[j] = minTemp[j];
		}
	}

	cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << " " << min(min(minDp[0], minDp[1]), minDp[2]);

	return 0;
}