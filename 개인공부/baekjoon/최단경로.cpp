//https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int> > v[300001];
int d[20001];

void dijkstra(int start_node)
{
	d[start_node] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, start_node));
	while(!pq.empty())
	{
		int current = pq.top().second;
		int start_to_current_dist = -pq.top().first;
		pq.pop();

		if (d[current] < start_to_current_dist)
			continue;

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second;
			int start_to_next_dist = start_to_current_dist + v[current][i].first;

			if(d[next] > start_to_next_dist)
			{
				d[next] = start_to_next_dist;
				pq.push(make_pair(-start_to_next_dist, next));
			}
		}
	}
}

int main()
{
	int V, E, K;

	cin >> V >> E >> K;

	for (int i = 1; i < V + 1; i++)
	{
		d[i] = INT_MAX;
	}

	for (int i = 0; i < E; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;
		v[start].push_back(make_pair(cost, end));
	}
	dijkstra(K);

	for (int i = 1; i < V + 1; i++)
	{
		if (d[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << d[i] << "\n";
	}
	return 0;
}