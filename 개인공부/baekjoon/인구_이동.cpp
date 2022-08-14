//https://www.acmicpc.net/problem/16234

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int arr[50][50];
int visited[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int> > v;
int sum;

void BFS(int x, int y)
{
	queue<pair<int, int> > q;
	
	visited[x][y] = true;
	q.push(make_pair(x, y));
	v.clear();
	v.push_back(make_pair(x, y));
	sum = arr[x][y];
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny])
			{
				int diff = abs(arr[x][y] - arr[nx][ny]);
				if (diff >= L && diff <= R)
				{
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
					sum += arr[nx][ny];

					v.push_back(make_pair(nx, ny));
				}
			}
		}

	}

}

int main()
{
	cin >> N >> L >> R;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool flag = true;
	while(flag)
	{
		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					BFS(i, j);
				}

				if (v.size() >= 2)
				{
					flag = true;
					for (int k = 0; k < v.size(); k++)
					{
						arr[v[k].first][v[k].second] = sum / v.size();
					}
				}
			}
		}

		if (flag)
			answer++;
	}
	cout << answer;

	return 0;
}