//https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	priority_queue<int> pq;
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		pq.push(-input);
	}

	while (pq.size() >= 2)
	{
		int first = -pq.top();
		pq.pop();
		int second = -pq.top();
		pq.pop();

		pq.push(-first - second);
		answer += first + second;
	}
	cout << answer;
	return 0;
}