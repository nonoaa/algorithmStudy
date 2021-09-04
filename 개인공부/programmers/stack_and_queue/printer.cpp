//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue< pair<int,int> > q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    while (1)
    {
        int curr = q.front().first;
        int index = q.front().second;
        int max = pq.top();
        if (curr != max)
        {
            q.pop();
            q.push(make_pair(curr, index));
        }
        else
        {
            answer++;
            if(index == location)
                break;
            else
            {
                q.pop();
                pq.pop();
            }
        }
    }

    return answer;
}
