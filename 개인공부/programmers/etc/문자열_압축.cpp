//https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int len = 1; len <= s.length() / 2; len++)
    {
        string temp = s.substr(0, len);
        string result = "";
        int cnt = 1;

        for (int i = len; i < s.length(); i += len)
        {
            string curr = s.substr(i, len);
            if (temp == curr)
                cnt++;
            else
            {
                if (cnt == 1)
                    result += temp;
                else
                {
                    result += to_string(cnt);
                    result += temp;
                }
                cnt = 1;
                temp = curr;
            }
            if (i + len >= s.length())
            {
                if (cnt == 1)
                    result += temp;
                else
                {
                    result += to_string(cnt);
                    result += temp;
                }
            }
        }

        answer = min(answer, (int)result.length());
    }
    return answer;
}