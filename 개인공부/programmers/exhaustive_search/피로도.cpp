//https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

#include <string>
#include <vector>

using namespace std;

bool visit[8];
int answer;

void DFS(int x, vector<vector<int>> dungeons, int k, int cnt)
{
    visit[x] = true;
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (dungeons[i][0] <= k && visit[i] == false)
            DFS(i, dungeons, k - dungeons[i][1], cnt + 1);
    }
    visit[x] = false;
    if (answer < cnt)
        answer = cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (dungeons[i][0] <= k)
            DFS(i, dungeons, k - dungeons[i][1], 1);
    }
    return answer;
}