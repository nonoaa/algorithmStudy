//https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int index = 0;
    
    sort(people.begin(), people.end());
    while (people.size() > index)
    {
        if (people.back() + people[index] <= limit)
            index++;
        people.pop_back();
        answer++;
    }
    
    return answer;
}
