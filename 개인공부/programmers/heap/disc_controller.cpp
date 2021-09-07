//https://programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int i = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    
    while (i < jobs.size() || !pq.empty())
    {
        if (jobs.size() > i && time >= jobs[i][0])
        {
            pq.push(jobs[i]);
            i++;
            continue;
        }
        else if (!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[i][0];
    }
    answer /= jobs.size();

    return answer;
}