//https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> info(n+1);
    vector<int> visited(n+1, 0);
    vector<int> distance(n+1, 0);
    queue<int> q;
    
    for (int i = 0; i < edge.size(); i++) {
        int first = edge[i][0];
        int second = edge[i][1];
        
        info[first].push_back(second);
        info[second].push_back(first);
    }
    q.push(1);
    visited[1] = 1;
    
    while(!q.empty())
    {
        int start = q.front();
        q.pop();
        
        for(int i = 0; i < info[start].size(); i++)
        {
            int next = info[start][i];
            if(!visited[next])
            {
                visited[next] = 1;
                distance[next] = distance[start] + 1;
                q.push(next);
            }
        }
    }
    sort(distance.begin(), distance.end(), greater<>());
    for(int i = 0; i < distance.size(); i++)
    {
        if(distance[i] == distance[0])
        {
            answer++;
        }
    }
    
    return answer;
}
