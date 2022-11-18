//https://www.acmicpc.net/problem/1012

#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[50][50];
bool visit[50][50];
int m, n, k;
int answer;

void DFS(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[nx][ny] == false && map[nx][ny] == 1)
		{
			DFS(nx, ny);
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		answer = 0;
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (visit[j][k] == false && map[j][k] == 1)
				{
					DFS(j, k);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}

	return 0;
}