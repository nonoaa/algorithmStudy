//https://www.acmicpc.net/problem/2178

#include <string>
#include <iostream>
#include <queue>

using namespace std;

string arr[100];
int dist[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
queue<pair<int, int>> q;

void bfs(int x, int y)
{
    q.push(make_pair(x, y));
    dist[x][y] = 1;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m
                && dist[nx][ny] == 0 && arr[nx][ny] == '1')
            {
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bfs(0, 0);
    cout << dist[n - 1][m - 1];
    return (0);
}

