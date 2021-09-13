//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int i = 0;
    queue<int> bridge;
    
    while(1)
    {
        answer++;
        
        if (bridge.size() == bridge_length)
        {
            sum -= bridge.front();
            bridge.pop();
        }
        
        
        if (sum + truck_weights[i] <= weight)
        {
            if (i >= truck_weights.size() - 1)
            {
                answer += bridge_length;
                break;
            }
            sum += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;
            
        }
        else
            bridge.push(0);
    }
    
    return answer;
}