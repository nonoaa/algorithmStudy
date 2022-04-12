//https://www.acmicpc.net/problem/3190

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int n, k, l;

int main()
{
	int time = 0;
	int direction = 0;
	queue<pair<int, int>> q;
	int answer = 0;
	int headR = 0, headC = 0;

	map[0][0] = -1;

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x;
		int y;
		cin >> x >> y;

		map[x - 1][y - 1] = 1;
	}
	cin >> l;
	q.push(make_pair(0, 0));
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		while (time < x)
		{
			headR += dr[direction];
			headC += dc[direction];
			time++;

			if (headR < 0 || headR >= n || headC < 0 || headC >= n || map[headR][headC] == -1)
			{
				if (answer == 0)
					answer = time;
			}
			q.push(make_pair(headR, headC));
			if (map[headR][headC] == 0)
			{
				map[q.front().first][q.front().second] = 0;
				q.pop();
			}
			map[headR][headC] = -1;
		}
		if (c == 'L')
		{
			if (direction == 0)
				direction = 3;
			else
				direction--;
		}
		if (c == 'D')
		{
			if (direction == 3)
				direction = 0;
			else
				direction++;
		}
	}

	while(answer == 0)
	{
		headR += dr[direction];
		headC += dc[direction];
		time++;

		if (headR < 0 || headR >= n || headC < 0 || headC >= n || map[headR][headC] == -1)
		{
			answer = time;
			break;
		}
		q.push(make_pair(headR, headC));
		if (map[headR][headC] == 0)
		{
			map[q.front().first][q.front().second] = 0;
			q.pop();
		}
		map[headR][headC] = -1;
	}
	cout << answer;

	return 0;
}