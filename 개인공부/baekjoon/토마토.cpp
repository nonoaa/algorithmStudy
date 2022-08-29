//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int M, N;
int map[1000][1000];
int curr;
int target;
int answer;
queue<pair<int, int> > q;

void BFS()
{
	while (!q.empty())
	{
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0)
			{
				map[nx][ny] = map[x][y] + 1;
				curr++;
				if (answer < map[nx][ny])
					answer = map[nx][ny];
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> M >> N;

	target = M * N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				curr++;
				q.push(make_pair(i, j));
			}
			if (map[i][j] == -1)
				target--;
		}
	}
	if (curr == target)
	{
		cout << "0";
		return 0;
	}

	BFS();

	if (target != curr)
		answer = -1;
	else
		answer--;
	cout << answer;

	return 0;
}