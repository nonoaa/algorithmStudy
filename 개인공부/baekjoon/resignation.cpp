//https://www.acmicpc.net/problem/14501

#include <iostream>

using namespace std;

int n;
int answer = 0;
int c[1000];
int p[1000];

void dfs(int index, int sum)
{
    if (index >= n)
    {
        if (sum > answer)
            answer = sum;
        return;
    }
    if (index + c[index] <= n)
        dfs(index + c[index], sum + p[index]);
    dfs(index + 1, sum);
}

int main()
{
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> p[i];
    }
    dfs(0, 0);

    cout << answer;
}
