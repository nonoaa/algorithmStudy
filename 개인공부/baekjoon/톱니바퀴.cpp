//https://www.acmicpc.net/problem/14891

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string gear[4];
int index[4];
int k, num, d;
int visit[4];

void solve(int gear_num, int direction)
{
	visit[gear_num] = 1;
	if (gear_num != 3 && visit[gear_num + 1] == 0)
	{
		if (gear[gear_num][(index[gear_num] + 2) % 8] != gear[gear_num + 1][(index[gear_num + 1] + 6) % 8])
		{
			solve(gear_num + 1, direction * -1);
		}
	}

	if (gear_num != 0 && visit[gear_num - 1] == 0)
	{
		if (gear[gear_num][(index[gear_num] + 6) % 8] != gear[gear_num - 1][(index[gear_num - 1] + 2) % 8])
		{
			solve(gear_num - 1, direction * -1);
		}
	}

	if (direction == -1)
		index[gear_num] = (index[gear_num] + 1) % 8;
	if (direction == 1)
		index[gear_num] = (index[gear_num] + 7) % 8;
}

int main()
{
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> gear[i];
	}
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> num >> d;
		solve(num - 1, d);
		for (int j = 0; j < 4; j++)
		{
			visit[j] = 0;
		}
	}

	for (int i = 3; i >= 0; i--)
	{
		answer = answer << 1;
		if (gear[i][index[i]] == '1')
		{
			answer += 1;
		}
	}
	cout << answer;

	return 0;
}