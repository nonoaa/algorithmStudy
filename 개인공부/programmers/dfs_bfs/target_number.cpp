//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int* answer, int i, int sum)
{
    if (i == numbers.size())
    {
        if (sum == target)
        {
            (*answer)++;
        }
        return;
    }
    dfs(numbers, target, answer, i + 1, sum + numbers[i]);
    dfs(numbers, target, answer, i + 1, sum - numbers[i]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, &answer, 0, 0);

    return answer;
}