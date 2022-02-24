https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do
    {
        bool check = true;
        for (int i = 0; i < data.size(); i++)
        {
            char ff = data[i][0];
            char sf = data[i][2];
            char num = data[i][4];
            
            int dist = friends.find(ff) - friends.find(sf);
            dist = abs(dist) - 1;
            if (data[i][3] == '=')
            {
                if (dist == num - '0')
                    continue;
            }
            if (data[i][3] == '<')
            {
                if (dist < num - '0')
                    continue;
            }
            if (data[i][3] == '>')
            {
                if (dist > num - '0')
                    continue;
            }
            check = false;
            break;
        }
        if (check)
            answer++;
    }while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}