//https://www.acmicpc.net/source/34464918

#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

void solution(int start, int mid, int end, int n) {
    if (n == 1) 
    {
        cout << start << " " << end << "\n";
    }
    else
    {
        solution(start, end, mid, n - 1);
        cout << start << " " << end << "\n";
        solution(mid, start, end, n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << "\n";
    solution(1, 2, 3, n);

    return 0;
}