//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > vec(1001);
bool dfs_visit[1001];
bool bfs_visit[1001];
queue<int> q;

void dfs(int index)
{
    cout << index << " ";
    dfs_visit[index] = true;

    for (int i = 0; i < (int)vec[index].size(); i++)
    {
        if(dfs_visit[vec[index][i]] == false)
        {
            dfs(vec[index][i]);
        }
    }
}

void bfs(int index)
{
    q.push(index);
    bfs_visit[index] = true;

    while (!q.empty())
    {
        index = q.front();
        q.pop();
        cout << index << " ";

        for (int i = 0; i < (int)vec[index].size(); i++)
        {
            if (bfs_visit[vec[index][i]] == false)
            {
                q.push(vec[index][i]);
                bfs_visit[vec[index][i]] = true;
            }
        }
    }
}

int main()
{
    int v, first, second;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        cin >> first >> second;
        vec[first].push_back(second);
        vec[second].push_back(first);
    }
    for (int i = 1; i <= n; i ++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);

    return (0);
}