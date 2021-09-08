//https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    return a.at(1) < b.at(1);
}

void dfs(int i, vector<vector<string>> tickets, vector<int> visit, deque<string> q, vector<string> &answer) {
    
    if (!answer.empty())
        return;
    if (i > tickets.size() - 1)
    {
        return;
    }
    if (tickets[i][0] == q.back() && visit[i] == 0)
    {
        visit[i] = 1;
        q.push_back(tickets[i][1]);
        dfs(0, tickets, visit, q, answer);
        visit[i] = 0;
        q.pop_back();
        dfs(i + 1, tickets, visit, q, answer);
    }
    else
        dfs(i + 1, tickets, visit, q, answer);
    if (tickets.size() + 1 == q.size() && answer.empty())
    {
        while (!q.empty())
        {
            answer.push_back(q.front());
            q.pop_front();
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> visit(tickets.size(), 0);
    deque<string> q;

    sort(tickets.begin(), tickets.end());
    sort(tickets.begin(), tickets.end(), cmp);
    q.push_back("ICN");
    dfs(0, tickets, visit, q, answer);

    return answer;
}
