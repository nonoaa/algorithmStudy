//https://programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities[i].length(); j++)
        {
            cities[i][j] = tolower(cities[i][j]);   
        }
        
        auto it = find(v.begin(), v.end(), cities[i]);

        if (it == v.end())
        {
            if (v.size() >= cacheSize)
            {
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
            answer += 5;
        }
        else
        {
            answer++;
            v.erase(it);
            v.push_back(cities[i]);
        }
    }
    
    return answer;
}
