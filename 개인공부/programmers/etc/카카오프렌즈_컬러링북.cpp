//https://programmers.co.kr/learn/courses/30/lessons/1829?language=cpp

#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool visit[100][100];

void dfs(int m, int n, int i, int j, vector<vector<int>> picture, int &area)
{
    visit[i][j] = true;
    area++;
    
    for (int k = 0; k < 4; k++)
    {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        
        if (nx >= 0 && nx < m && ny >= 0 && ny < n
           && picture[i][j] == picture[nx][ny] && visit[nx][ny] == false)
        {
            dfs(m, n, nx, ny, picture, area);
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int area = 0;
    
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            visit[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == false && picture[i][j] != 0)
            {
                dfs(m, n, i, j, picture, area);
                if (area > max_size_of_one_area)
                    max_size_of_one_area = area;
                number_of_area++;
                area = 0;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}