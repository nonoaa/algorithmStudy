//https://www.acmicpc.net/problem/15591

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int> > video[5001];
bool visit[5001];

void BFS(int k, int v)
{
	for (int i = 0; i < 5001; i++)
	{
		visit[i] = false;
	}
	queue<int> q;
	int cnt = 0;

	visit[v] = true;
	q.push(v);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < video[curr].size(); i++)
		{
			int next = video[curr][i].first;
			int cost = video[curr][i].second;
			if (!visit[next] && cost >= k)
			{
				cnt++;
				visit[next] = true;
				q.push(next);
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	int q;

	cin >> n >> q;

	for (int i = 0; i < n - 1; i++)
	{
		int p, q, r;

		cin >> p >> q >> r;
		video[p].push_back(make_pair(q, r));
		video[q].push_back(make_pair(p, r));
	}

	for (int i = 0; i < q; i++)
	{
		int k, v;
		
		cin >> k >> v;
		BFS(k, v);
	}

	return 0;
}