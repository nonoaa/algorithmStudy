//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    int x = 0;
    int y = 3;
    
    while(1)
    {
        if (total % y == 0)
        {
            x = total / y;
            if((x - 2) * (y - 2) == yellow)
            {
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
        y++;
    }
    
    return answer;
}
