//https://programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long sum = 0;
    long long min = 1, max, mid;
    max = (long long)(*max_element(times.begin(), times.end())) * (long long)n;
    answer = max;

    while (min <= max)
    {
        sum = 0;
        mid = (min + max) / 2;

        for (int i = 0; i < times.size(); i++)
        {
            sum += mid / times[i];
        }
        if (sum < n) {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
            answer = mid;
        }
    }

    return answer;
}
