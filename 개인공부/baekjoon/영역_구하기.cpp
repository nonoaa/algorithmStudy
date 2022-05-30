//https://www.acmicpc.net/problem/2583

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
int arr[101][101];
int visit[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int area;
vector<int> answer;

void dfs(int x, int y)
{
	arr[x][y] = 1;
	area++;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == 0)
			dfs(nx, ny);
	}
}

int main()
{
	cin >> m >> n >> k;
	int cnt = 0;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				arr[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				area = 0;
				dfs(i, j);
				answer.push_back(area);
				cnt++;
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << cnt << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}