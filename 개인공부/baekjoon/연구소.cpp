#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int answer;

void bfs(vector<vector<int>> v)
{
	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				v[nx][ny] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 0)
				cnt++;
		}
	}
	answer = max(cnt, answer);
}

void dfs(vector<vector<int>> v, int x, int y, int cnt)
{
	v[x][y] = 1;
	if (cnt == 3)
	{
		bfs(v);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 0)
			{
				dfs(v, i, j, cnt + 1);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 0)
			{
				dfs(v, i, j, 1);
			}
		}
	}

	cout << answer;

	return 0;
}