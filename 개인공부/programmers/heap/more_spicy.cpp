//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    for (int i = 0; i < scoville.size() - 1; i++)
    {
        if (pq.top() < K)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            pq.push(first + (second * 2));
            answer++;
        }
        else
            return answer;
    }
    if (pq.top() >= K)
        return answer;
    else
        return -1;
}