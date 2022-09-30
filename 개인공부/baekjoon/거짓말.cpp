//https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>

using namespace std;

int parent[51];
vector<int> knowing;
vector<vector<int> > party(50);

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return x = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main()
{
	int answer = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		knowing.push_back(temp);
	}

	int p, num, prev;
	for (int i = 0; i < m; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			if (j >= 1)
			{
				prev = num;
				cin >> num;
				Union(prev, num); 
			}
			else
				cin >> num;
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			for (int l = 0; l < k; l++)
			{
				if (Find(party[i][j]) == Find(knowing[l]))
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			answer++;
		}
	}
	cout << answer;

	return 0;
}