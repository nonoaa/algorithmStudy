//https://www.acmicpc.net/problem/5430

#include <string>
#include <iostream>
#include <deque>

using namespace std;

deque<int> d[100];
bool is_reverse[100];

int main()
{
    int t;
    cin >> t;
    string p, n, numbers;
    
    for (int i = 0; i < t; i++)
    {
        cin >> p >> n >> numbers;
        int j = 0;
        int num = 0;
        
        while (numbers[j])
        {
            if(numbers[j] >= '0' && numbers[j] <= '9')
            {
                num = (num * 10) + numbers[j] - '0';
            }
            else if (num != 0)
            {
                d[i].push_back(num);
                num = 0;
            }
            j++;
        }
        
        j = 0;
        while (p[j])
        {
            if (p[j] == 'R')
                is_reverse[i] = !(is_reverse[i]);
            else if (p[j] == 'D')
            {
                if (d[i].empty())
                {
                    d[i].push_back(-1);
                    break;
                }
                else
                {
                    if (is_reverse[i])
                        d[i].pop_back();
                    else
                        d[i].pop_front();
                }
            }
            j++;
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        if (!d[i].empty() && d[i].front() == -1)
        {
            cout << "error\n";
            continue;
        }
        cout << "[";
        while (!d[i].empty())
        {
            if (is_reverse[i])
            {
                cout << d[i].back();
                d[i].pop_back();
            }
            else
            {
                cout << d[i].front();
                d[i].pop_front();
            }
            if (!d[i].empty())
                cout << ",";
        }
        cout << "]\n";
    }
    
    return (0);
}

