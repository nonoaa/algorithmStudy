//https://programmers.co.kr/learn/courses/30/lessons/67257

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<char> prior = { '*', '+', '-' };
    vector<long long> num;
    vector<char> op;

    long long temp = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
            temp = temp * 10 + expression[i] - '0';
        else
        {
            num.push_back(temp);
            temp = 0;
            op.push_back(expression[i]);
        }
    }
    num.push_back(temp);

    do {
        vector<long long> temp_num = num;
        vector<char> temp_op = op;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < temp_op.size(); j++)
            {
                if (prior[i] == temp_op[j])
                {
                    if (temp_op[j] == '*')
                        temp_num[j] = temp_num[j] * temp_num[j + 1];
                    else if (temp_op[j] == '+')
                        temp_num[j] = temp_num[j] + temp_num[j + 1];
                    else if (temp_op[j] == '-')
                        temp_num[j] = temp_num[j] - temp_num[j + 1];
                    temp_num.erase(temp_num.begin() + j + 1);
                    temp_op.erase(temp_op.begin() + j);
                    j--;
                }
            }
        }
        if (abs(temp_num[0]) > answer)
            answer = abs(temp_num[0]);
    } while (next_permutation(prior.begin(), prior.end()));

    return answer;
}