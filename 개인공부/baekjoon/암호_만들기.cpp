//https://www.acmicpc.net/problem/1759

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int l, c;

void DFS(int index, string temp, string input, int vcount, int ccount)
{
    if (temp.length() == (size_t)l && vcount >= 1 && ccount >= 2)
    {
        cout << temp << "\n";
        return;
    }
    if (index == c)
        return;
    string vowels = "aeiou";
    if (vowels.find(input[index]) != string::npos)
        DFS(index + 1, temp + input[index], input, vcount + 1, ccount);
    else
        DFS(index + 1, temp + input[index], input, vcount, ccount + 1);
    DFS(index + 1, temp, input, vcount, ccount);
}

int main()
{
    string answer = "";
    string input = "";

    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        char c;
        cin >> c;
        input += c;
    }
    string temp = "";
    sort(input.begin(), input.end());
    DFS(0, temp, input, 0, 0);

    cout << answer;
    return 0;
}