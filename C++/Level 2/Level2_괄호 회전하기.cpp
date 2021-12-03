#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool is_right_Blanket(string s)
{
	stack<char> tmp;

	for (char c : s)
	{
		if (c == '(' || c == '{' || c == '[')
			tmp.push(c);

		else if (tmp.empty())
			return false;

		else if (c == ')' && tmp.top() == '(')
			tmp.pop();

		else if (c == ']' && tmp.top() == '[')
			tmp.pop();

		else if (c == '}' && tmp.top() == '{')
			tmp.pop();
	}

	return tmp.empty();
}

int solution(string s) {
	int answer = 0;

	string s_original = s;

	for (int i = 0; i < s.length(); i++)
	{
		if (is_right_Blanket(s))
			answer++;

		char front = s[0];

		s.erase(s.begin());

		s += front;
	}

	return answer;
}

void main()
{
	cout << solution("((()))");
}