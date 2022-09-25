//https://www.acmicpc.net/problem/15684

#include <iostream>

using namespace std;

int n, m, h;
int map[32][12];
int answer = 4;

void DFS(int max, int cnt, int x, int y)
{
    if (answer <= cnt)
        return;
    bool flag = true;

    for (int i = 1; i <= n; i++)
    {
        int curr = i;
        for (int j = 1; j <= h; j++)
        {
            if (map[j][curr])
                curr++;
            else if (map[j][curr - 1])
                curr--;
        }
        if (curr != i)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        answer = cnt;
        return;
    }
    if (cnt == max)
        return;

    for (int i = x; i <= h; i++)
    {
        for (int j = y; j <= n; j++)
        {
            if (map[i][j] || map[i][j + 1])
                continue;
            map[i][j] = 1;
            DFS(max, cnt + 1, i, j);
            map[i][j] = 0;
        }
        y = 1;
    }
}

int main()
{
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        DFS(i, 0, 1, 1);
    }

    if (answer == 4)
        answer = -1;
    cout << answer;
    return 0;
}