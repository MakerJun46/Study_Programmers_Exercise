#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool is_right_string(string u)
{
	stack<char> s;

	for (int i = 0; i < u.length(); i++)
	{
		if (u[i] == '(')     // 열리는 괄호면 스택에 푸쉬
			s.push(u[i]);
		else
		{
			if (s.empty())  // 닫히는 괄호가 나왔는데 열리는 괄호가 매칭 안되면 올바르지 않은 문자열
				return false;

			s.pop();    // 닫히는 괄호를 만나면 스택에 있는 열린 괄호를 하나씩 pop(매칭)
		}
	}
	return s.empty() ? true : false; // for문 돌고 나서 스택이 비어있으면 올바른 문장
}

string reverse_bracket(string s)
{
	string reverse_s = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			reverse_s += ")";
		else
			reverse_s += "(";
	}

	return reverse_s;
}

string solution(string p) {
	string answer = "";

	//1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
	if (p.empty())
		return answer;

	//2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
	//단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며,
	//v는 빈 문자열이 될 수 있습니다.

	int open_bracket = 0;
	int close_bracket = 0;
	string u;
	string v;

	for (int i = 0; i < p.length(); i++)
	{
		if (open_bracket != 0 && open_bracket == close_bracket)
		{
			v = p.substr(i);
			break;
		}
		if (p[i] == '(')
		{
			u += "(";
			open_bracket++;
		}
		else
		{
			u += ")";
			close_bracket++;
		}
	}

	/*
	3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
		3 - 1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
	*/
	if (is_right_string(u))
	{
		answer += u + solution(v);
	}

	/*
	4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
		4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
		4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
		4 - 3. ')'를 다시 붙입니다.
		4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
		4 - 5. 생성된 문자열을 반환합니다.
	*/

	else
	{
		answer += "(" + solution(v) + ")" + reverse_bracket(u.substr(1, u.length() - 2));
	}

	return answer;
}

void main()
{

	cout << solution("()))((()");
}