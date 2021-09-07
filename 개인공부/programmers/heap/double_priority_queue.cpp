//https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    deque<int> d;

    for (int i = 0; i < operations.size(); i++)
    {
        int num = 0;
        int len = operations[i].size();
        if (operations[i][0] == 'I')
        {
            num = stoi(operations[i].substr(2, len));
            d.push_back(num);
            sort(d.begin(), d.end());
        }
        else if (operations[i][0] == 'D')
        {
            if (!d.empty())
            {
                if (operations[i][2] == '1')
                {
                    d.pop_back();
                }
                else if (operations[i][2] == '-')
                {
                    if (operations[i][3] == '1')
                    {
                        d.pop_front();
                    }
                }
            }
        }

    }
    if (!d.empty())
    {
        answer[0] = d.back();
        answer[1] = d.front();
        return answer;
    }

    return { 0, 0 };
}