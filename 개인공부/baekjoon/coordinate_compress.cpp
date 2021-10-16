//https://www.acmicpc.net/problem/18870

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    map<int,int> m;
    int input;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v[i] = input;
        v2[i] = input;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (m[v[i]] == 0)
            m[v[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << m[v2[i]];
        if (i != n - 1)
            cout << " ";
    }
    return (0);
}