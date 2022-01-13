//https://www.acmicpc.net/problem/2468

#include <iostream>

using namespace std;

int arr[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visit[100][100];
int n;
int min_height = 2147483647, max_height = 0;
int answer, cnt;

void dfs(int x, int y, int height)
{
    if (x == n)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n
            && visit[nx][ny] == false && arr[nx][ny] >= height)
        {
            visit[nx][ny] = true;
            dfs(nx, ny, height);
        }
    }
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            max_height = max(max_height, arr[i][j]);
            min_height = min(min_height, arr[i][j]);
        }
    }
    
    for (int h = min_height; h <= max_height; h++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit[i][j] == false && arr[i][j] >= h)
                {
                    visit[i][j] = true;
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visit[i][j] = false;
            }
        }
        cnt = 0;
    }
    
    cout << answer;
    return (0);
}
