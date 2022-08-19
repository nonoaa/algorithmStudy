//https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[100][100];
bool visit[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS()
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int> > q;

	q.push(make_pair(0, 0));
	visit[0][0] = true;
	map[0][0] = 2;

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && (map[nx][ny] == 0 || map[nx][ny] == 2) && visit[nx][ny] == false)
			{
				visit[nx][ny] = true;
				map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				total++;
		}
	}
	int answer = 0;
	while (total > 0)
	{
		answer++;
		BFS();
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				int cnt = 0;
				if (map[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 2)
						{
							cnt++;
						}
					}
					if (cnt >= 2)
					{
						map[i][j] = 0;
						total--;
					}
				}
			}
		}
	}
	cout << answer;

	return 0;
}