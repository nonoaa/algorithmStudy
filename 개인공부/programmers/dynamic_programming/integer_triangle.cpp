//https://programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int to_add = 0;

    for (int i = triangle.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < triangle[i].size() - 1; j++)
        {
            if (triangle[i][j] < triangle[i][j + 1])
                to_add = triangle[i][j + 1];
            else
                to_add = triangle[i][j];
            triangle[i - 1][j] += to_add;
        }
    }
    answer = triangle[0][0];
    return answer;
}