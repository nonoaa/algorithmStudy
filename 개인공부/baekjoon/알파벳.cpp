//https://www.acmicpc.net/problem/1987

#include <iostream>

using namespace std;

char map[20][20];
bool visit[20][20];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool alp[256];
int R, C;
int answer;

void DFS(int x, int y, int cnt)
{
	visit[x][y] = true;
	alp[map[x][y]] = true;
	if (cnt > answer)
		answer = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visit[nx][ny] && !alp[map[nx][ny]])
		{
			DFS(nx, ny, cnt + 1);
		}
	}
	visit[x][y] = false;
	alp[map[x][y]] = false;
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
	DFS(0, 0, 1);
	cout << answer;


	return 0;
}