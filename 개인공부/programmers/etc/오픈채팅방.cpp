//https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer; 
    queue<pair<int, string>> q;
    unordered_map<string, string> um;
    
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i].substr(0,5) == "Enter")
        {
            int j = 6;
            string id = "";
            string nick = "";
            while (record[i][j] != ' ')
            {
                id += record[i][j];
                j++;
            }
            while (j++ < record[i].length() - 1)
            {
                nick += record[i][j];
            }
            um[id] = nick;
            q.push(make_pair(0, id));
        }
        else if (record[i].substr(0,5) == "Leave")
        {
            int j = 6;
            string id = "";

            while (j < record[i].length())
            {
                id += record[i][j++];
            }
            q.push(make_pair(1, id));
        }
        else if (record[i].substr(0,6) == "Change")
        {
            int j = 7;
            string id = "";
            string nick = "";
            while (record[i][j] != ' ')
            {
                id += record[i][j];
                j++;
            }
            while (j++ < record[i].length() - 1)
            {
                nick += record[i][j];
            }
            um[id] = nick;
        }
    }
    
    while(!q.empty())
    {
        if (q.front().first == 0)
        {
            string nick = um[q.front().second];
            answer.push_back(nick + "님이 들어왔습니다.");
            q.pop();
        }
        else if (q.front().first == 1)
        {
            string nick = um[q.front().second];
            answer.push_back(nick + "님이 나갔습니다.");
            q.pop();
        }
    }
    return answer;
}