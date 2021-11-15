//https://www.acmicpc.net/problem/5052

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int answer[51] = {0, };
    
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<string> str(n);
        for (int j = 0; j < n; j++)
        {
            cin >> str[j];
        }
        sort(str.begin(), str.end());
        for (int j = 0; j < n - 1; j++)
        {
            if (str[j] == str[j+1].substr(0, str[j].length()))
            {
                answer[i] = 1;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (answer[i] == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    return (0);
}

