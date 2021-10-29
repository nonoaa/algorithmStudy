//https://www.acmicpc.net/problem/1780

#include <iostream>

using namespace std;

int arr[2187][2187];
int answer[3];

void solve(int x, int y, int n)
{
    bool b = true;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[i][j] != arr[x][y])
                b = false;
        }
    }
    if (b)
        answer[arr[x][y] + 1]++;
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                solve(x + ((n/3) * i), y + ((n/3) * j), n/3);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0, 0, n);
    cout << answer[0] << "\n" << answer[1] << "\n" << answer[2];
    
}

