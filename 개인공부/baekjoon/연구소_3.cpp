//https://www.acmicpc.net/problem/17142

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;
int map[50][50];
int answer = 2147483647;
vector<pair<int, int> > viruses;
bool v_visit[10];
int m_visit[50][50];
int total;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS()
{
    queue<pair<int, int> > q;
    int cnt = 0, time = 0;

    for (int i = 0; i < (int)viruses.size(); i++)
    {
        if (v_visit[i])
        {
            m_visit[viruses[i].first][viruses[i].second] = 0;
            q.push(make_pair(viruses[i].first, viruses[i].second));
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && (map[nx][ny] == 0 || map[nx][ny] == 2) && m_visit[nx][ny] == -1)
            {
                m_visit[nx][ny] = m_visit[x][y] + 1;
                q.push(make_pair(nx, ny));
                if (map[nx][ny] == 0)
                {
                    cnt++;
                    time = m_visit[nx][ny];
                }
            }
        }
    }
    if (cnt == total && time < answer)
    {
        answer = time;
    }
}

void DFS(int index, int cnt, int v_size)
{
    if (cnt == m)
    {
        memset(m_visit, -1, sizeof(m_visit));
        BFS();
        return ;
    }

    for (int i = index; i < v_size; i++)
    {
        v_visit[i] = true;
        DFS(i + 1, cnt + 1, v_size);
        v_visit[i] = false;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                viruses.push_back(make_pair(i, j));
            else if (map[i][j] == 0)
                total++;
        }
    }
    DFS(0, 0, viruses.size());
    if (answer == 2147483647)
        answer = -1;
    cout << answer;
    return 0;
}