#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    /* // 효율성 0점
    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (s.empty())
            break;

        char tmp = s[i];

        if (tmp == s[i + 1])
        {
            s.erase(i, 2);
            if (i == 0)
                i--;
            else
                i -= 2;
        }
    }
    */
    
    stack<char> tmp;

    for (int i = 0; i < s.length(); i++)
    {
        if (!tmp.empty() && tmp.top() == s[i])
            tmp.pop();
        else
            tmp.push(s[i]);
    }
    
    return (int)tmp.empty();
}

void main()
{
    cout << solution("baabaa");
}