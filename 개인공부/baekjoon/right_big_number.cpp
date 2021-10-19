//https://www.acmicpc.net/problem/17298

#include <stack>
#include <iostream>

using namespace std;

int n;
stack<int> s;
int arr[1000000];
int answer[1000000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    answer[n - 1] = -1;
    s.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            answer[i] = -1;
        else
            answer[i] = s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }

    return (0);
}