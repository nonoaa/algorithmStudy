//https://www.acmicpc.net/problem/10026

#include <iostream>

using namespace std;

char arr[100][100];
bool visit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

bool check(char a, char b)
{
    if(a == 'R' || a == 'G')
    {
        if (b == 'R' || b == 'G')
            return true;
    }
    else if (a == b)
        return true;
    return false;
}

void dfs1(int i, int j)
{
    visit[i][j] = true;
    char curr = arr[i][j];
    
    for (int k = 0; k < 4; k++)
    {
        if (i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= n || j + dy[k] >= n)
            continue;
        if (visit[i + dx[k]][j + dy[k]] == false && curr == arr[i + dx[k]][j + dy[k]])
            dfs1(i + dx[k], j + dy[k]);
    }
}

void dfs2(int i, int j)
{
    visit[i][j] = true;
    char curr = arr[i][j];
    
    for (int k = 0; k < 4; k++)
    {
        if (i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= n || j + dy[k] >= n)
            continue;
        if (visit[i + dx[k]][j + dy[k]] == false && check(curr, arr[i + dx[k]][j + dy[k]]))
            dfs2(i + dx[k], j + dy[k]);
    }
}

int main()
{
    int answer1 = 0, answer2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == false)
            {
                dfs1(i, j);
                answer1++;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == false)
            {
                dfs2(i, j);
                answer2++;
            }
        }
    }
    
    cout << answer1 << " " << answer2;
    return (0);
}

