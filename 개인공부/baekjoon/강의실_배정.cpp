//https://www.acmicpc.net/problem/11000

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        v[i] = make_pair(s, t);
    }
    
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= pq.top())
            pq.pop();
        pq.push(v[i].second);
    }
    cout << pq.size();
    return (0);
}

