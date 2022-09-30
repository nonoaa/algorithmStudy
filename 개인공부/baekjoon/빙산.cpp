//https://www.acmicpc.net/problem/2573

#include <iostream>
#include <memory.h>

using namespace std;

int n, m;
int map[300][300];
bool visit[300][300];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void melting(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (map[x][y] > 0 && map[nx][ny] == 0 && visit[nx][ny] == false)
				map[x][y]--;
		}
	}
}

void DFS(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (map[nx][ny] > 0 && visit[nx][ny] == false)
				DFS(nx, ny);
		}
	}
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

	int time = 0;
	while (true)
	{
		int count = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0)
				{
					melting(i, j);
				}
			}
		}
		time++;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0 && visit[i][j] == false)
				{
					DFS(i, j);
					count++;
				}
			}
		}

		if (count == 0)
		{
			time = 0;
			break;
		}
		else if (count != 1)
		{
			break;
		}
	}
	cout << time;

	return 0;
}