//https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> uos;

    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 0; i < numbers.size(); i++)
        {
            int n = stoi(numbers.substr(0, i + 1));
            int is_prime = 1;
            if (n == 0 || n == 1)
                is_prime = 0;
            for (int j = 2; j <= sqrt(n); j++)
            {
                if (n % j == 0)
                {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime)
            {
                uos.insert(n);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = uos.size();
    return answer;
}