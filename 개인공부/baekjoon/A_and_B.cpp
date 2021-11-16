//https://www.acmicpc.net/problem/12904

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int answer = 0;
    
    while (1)
    {
        if (s.length() == t.length())
        {
            if (s == t)
            {
                answer = 1;
            }
            break;
        }
        
        if (t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        
    }
    
    cout << answer;
    
    return (0);
}

