//https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> string_num;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string_num.push_back(to_string(numbers[i]));
    }
    sort(string_num.begin(), string_num.end(), cmp);
    for(int i = 0; i < string_num.size(); i++)
    {
        answer += string_num[i];
    }
    if (string_num[0][0] == '0')
        return "0";
    return answer;
}