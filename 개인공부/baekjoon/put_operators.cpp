//https://www.acmicpc.net/problem/14888

#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int n;
int operands[11];
int operators[4];
int max_res = -1000000000;
int min_res = 1000000000;

void dfs(int index, int result)
{
    if (index >= n)
    {
        max_res = max(result, max_res);
        min_res = min(result, min_res);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
                dfs(index + 1, result + operands[index]);
            else if (i == 1)
                dfs(index + 1, result - operands[index]);
            else if (i == 2)
                dfs(index + 1, result * operands[index]);
            else if (i == 3)
                dfs(index + 1, result / operands[index]);
            operators[i]++;
        }
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operands[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }
    dfs(1, operands[0]);
    cout << max_res << "\n" << min_res;

    return (0);
}

