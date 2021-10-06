//https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_cnt;
    map<string, map<int, int>> play_cnt;

    for (int i = 0; i < genres.size(); i++)
    {
        genre_cnt[genres[i]] += plays[i];
        play_cnt[genres[i]][i] = plays[i];
    }
    while(genre_cnt.size() > 0)
    {
        int max = 0;
        string max_genre = "";
        int index = 0;
        int cnt = 0;
        
        for (auto it = genre_cnt.begin(); it != genre_cnt.end(); it++)
        {
            if(it->second > max)
            {
                max = it->second;
                max_genre = it->first;
            }
        }
        genre_cnt.erase(max_genre);
        while (play_cnt[max_genre].size() > 0)
        {
            max = 0;
            for (auto it = play_cnt[max_genre].begin(); it != play_cnt[max_genre].end(); it++)
            {
                if (it->second > max)
                {
                    max = it->second;
                    index = it->first;
                }

            }
            play_cnt[max_genre].erase(index);
            answer.push_back(index);
            if (++cnt >= 2)
                break;;
        }
    }

    return answer;
}

