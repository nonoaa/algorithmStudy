//https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>

using namespace std;

int answer, cnt;
char aeiou[5] = {'A', 'E', 'I', 'O', 'U'};

void DFS(string str, string word)
{
    if (str == word)
    {
        answer = cnt;
        return;
    }
    if (str.length() > 5)
    {
        return;
    }
    cnt++;
    for (int i = 0; i < 5; i++)
    {
        DFS(str + aeiou[i], word);
    }
}

int solution(string word) {
    string temp = "";
    DFS(temp, word);
    
    return answer;
}