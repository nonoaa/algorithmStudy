//https://www.acmicpc.net/problem/16916
//KMP알고리즘

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.length();
    int j = 0;
    vector<int> pi(m, 0);
    
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

bool kmp(string s, string p)
{
    bool answer = false;
    auto pi = getPi(p);
    int n = (int)s.length();
    int m = (int)p.length();
    int j = 0;
    
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j-1];
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                answer = true;
                j = pi[j];
            }
            else
                j++;
        }
    }
    
    return answer;
}

int main()
{
    string s, p;
    cin >> s >> p;
    if (kmp(s,p))
        cout << 1;
    else
        cout << 0;
    
    return (0);
}

