https://programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(vector<string> place, int x, int y, int distance, bool& check, int visit[][5])
{
    for (int i = 0; i < 4; i++)
    {
        if (distance >= 2 || !check)
            return;

        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5 && !visit[next_x][next_y]
            && !visit[next_x][next_y] && place[next_x][next_y] != 'X')
        {
            if (place[next_x][next_y] == 'P')
            {
                check = false;
                return;
            }
            else
            {
                visit[next_x][next_y] = true;
                dfs(place, next_x, next_y, distance + 1, check, visit);
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int k = 0; k < places.size(); k++)
    {
        int visit[5][5] = { 0, };
        bool check = true;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (places[k][i][j] == 'P')
                {
                    visit[i][j] = true;
                    dfs(places[k], i, j, 0, check, visit);
                }
                if (!check)
                {
                    break;
                }
            }
            if (!check)
            {
                break;
            }
        }

        if (check)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}