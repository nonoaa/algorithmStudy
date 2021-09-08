//https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp

#include <string>
#include <vector>

using namespace std;


void dfs(int i, int n, vector<vector<int>> computers, vector<int> &visit)
{
    visit[i] = 1;

    for (int j = 0; j < n; j++)
    {
        if(visit[j] == 0 && computers[i][j])
            dfs(j, n, computers, visit);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visit(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            dfs(i, n, computers, visit);
            answer++;
        }
    }

    return answer;
}