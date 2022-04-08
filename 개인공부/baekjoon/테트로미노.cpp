//https://www.acmicpc.net/problem/14500

#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[500][500];
int visit[500][500];
int max_sum;
int n, m;

void find_last_shape(int x, int y)
{
	if (x - 1 >= 0 && x + 1 < n && y + 1 < m)
		max_sum = max(max_sum, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	if (x - 1 >= 0 && x + 1 < n && y - 1 >= 0)
		max_sum = max(max_sum, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m)
		max_sum = max(max_sum, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	if (x + 1 < n && y - 1 >= 0 && y + 1 < m)
		max_sum = max(max_sum, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]);
}

void dfs(int x, int y, int sum, int depth)
{
	visit[x][y] = 1;

	if (depth == 4)
	{
		max_sum = max(max_sum, sum);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == 0)
		{
			dfs(nx, ny, sum + map[nx][ny], depth + 1);
			visit[nx][ny] = 0;
		}
	}

	visit[x][y] = 0;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, map[i][j], 1);
			find_last_shape(i, j);
		}
	}

	cout << max_sum;
	return 0;
}