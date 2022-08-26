//https://www.acmicpc.net/problem/16120

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string input;
	cin >> input;

	int p_count = 0;
	bool answer = true;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'P')
			p_count++;
		else
		{
			if (p_count >= 2 && input[i + 1] == 'P')
				p_count -= 2;
			else
			{
				answer = false;
				break;
			}
		}
	}
	if (p_count != 1)
		answer = false;

	if (answer)
		cout << "PPAP";
	else
		cout << "NP";

	return 0;
}