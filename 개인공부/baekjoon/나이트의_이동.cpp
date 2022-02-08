//https://www.acmicpc.net/problem/7562

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dist[300][300] = { -1, };
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> v;
queue<pair<int, int>> q;

void bfs(int l, int curX, int curY, int tarX, int tarY)
{
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			dist[i][j] = -1;
		}
	}
	q.push(make_pair(curX, curY));
	dist[curX][curY] = 0;
	while (!q.empty())
	{
		curX = q.front().first;
		curY = q.front().second;
		q.pop();
		if (curX == tarX && curY == tarY)
		{
			v.push_back(dist[curX][curY]);
			while (!q.empty())
			{
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (0 <= nx && nx < l && 0 <= ny && ny < l && dist[nx][ny] == -1)
			{
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[curX][curY] + 1;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int l, curX, curY, tarX, tarY;
		cin >> l >> curX >> curY >> tarX >> tarY;
		bfs(l, curX, curY, tarX, tarY);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}