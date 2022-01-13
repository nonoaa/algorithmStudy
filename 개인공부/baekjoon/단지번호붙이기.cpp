//https://www.acmicpc.net/problem/2667

#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string arr[25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visit[25][25];
int n;
queue<pair<int, int>> q;
int cnt;
vector<int> answers;

void bfs(int x, int y)
{
    q.push(make_pair(x, y));
    visit[x][y] = true;
    int house_count = 1;
    
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n
                && visit[nx][ny] == false && arr[nx][ny] == '1')
            {
                q.push(make_pair(nx,ny));
                visit[nx][ny] = true;
                house_count++;
            }
        }
    }
    answers.push_back(house_count);
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == false && arr[i][j] == '1')
            {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    sort(answers.begin(), answers.end());
    
    cout << cnt << "\n";
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << "\n";
    }
    return (0);
}

