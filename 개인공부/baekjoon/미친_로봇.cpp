//https://www.acmicpc.net/problem/1405

#include <iostream>

using namespace std;

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
double per[4];
int map[30][30];
double res;

void DFS(int x, int y, double percent)
{
	if (map[x][y] == n + 1)
	{
		res += percent;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == 0)
		{
			map[nx][ny] = map[x][y] + 1;
			DFS(nx, ny, percent * per[i]);
			map[nx][ny] =  0;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		double x;
		cin >> x;
		per[i] = x / 100;
	}

	map[15][15] = 1;
	DFS(15, 15, 1.0);
	cout.precision(18);
	cout << fixed << res;
	
	return 0;
}