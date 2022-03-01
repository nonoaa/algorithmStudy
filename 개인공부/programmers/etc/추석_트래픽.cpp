//https://programmers.co.kr/learn/courses/30/lessons/17676

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> v;

    for (int i = 0; i < lines.size(); i++)
    {
        int time = 0;
        time += stoi(lines[i].substr(11, 2)) * 3600 * 1000;
        time += stoi(lines[i].substr(14, 2)) * 60 * 1000;
        time += stoi(lines[i].substr(17, 2)) * 1000;
        time += stoi(lines[i].substr(20, 3));

        int proc = 0;
        proc += stoi(lines[i].substr(24, 1)) * 1000 - 1;
        string temp = "";

        for (int j = 26; j < 29; j++)
        {
            if (j < lines[i].length() - 1)
                temp += lines[i][j];
            else
                temp += '0';
        }
        proc += stoi(temp);
        v.push_back(make_pair(time - proc, time));
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < v.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].first - v[i].second < 1000)
                count++;
        }
        answer = max(count, answer);
    }

    return answer;
}