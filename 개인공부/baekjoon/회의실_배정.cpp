//https://www.acmicpc.net/problem/1931

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int curr = 0;
    int answer = 0;
    vector<pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        time.push_back(make_pair(second, first));
    }

    sort(time.begin(), time.end());

    for (int i = 0; i < n; i++)
    {
        if (curr <= time[i].second)
        {
            curr = time[i].first;
            answer++;
        }
    }
    cout << answer;
}
