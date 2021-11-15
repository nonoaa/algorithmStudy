//https://www.acmicpc.net/problem/9935

#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str, explode;
    cin >> str >> explode;
    string answer = "";
    
    for (int i = 0; i < str.length(); i++)
    {
        answer.push_back(str[i]);
        if (answer.back() == explode[explode.length()-1])
        {
            int cnt = 1;
            int index = 1;
            for (int j = explode.length() - 2; j >= 0 && i - index >= 0; j--)
            {
                if (answer[answer.length() - 1 - index] == explode[j])
                    cnt++;
                index++;
            }
            if (cnt == explode.length())
            {
                for(int j = 0; j < explode.length(); j++)
                {
                    answer.pop_back();
                }
            }
        }
    }
    
    if (answer == "")
        cout << "FRULA";
    else
        cout << answer;
    
    return (0);
}
