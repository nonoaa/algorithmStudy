//https://www.acmicpc.net/problem/2644

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, targetx, targety, m;
int arr[101][101];
int visit[101];

void bfs()
{
	queue<int> q;
	int cnt = 0;

	q.push(targetx);
	
	while (!q.empty())
	{
		int curr;

		curr = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[curr][i] == 1 && visit[i] == 0)
			{
				q.push(i);
				visit[i] = visit[curr] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> targetx >> targety >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;

		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	bfs();

	if (visit[targety] == 0)
		cout << -1;
	else
		cout << visit[targety];

	return 0;
}