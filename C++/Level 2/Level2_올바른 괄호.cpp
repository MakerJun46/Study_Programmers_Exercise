#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    cout << solution("()()") << endl;
    cout << solution(")()(") << endl;
}