#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    stringstream ss(s);

    string tmp;

    if (s[0] == ' ')
        answer += " ";

    while (getline(ss, tmp, ' '))
    {
        tmp[0] = toupper(tmp[0]);

        for (int i = 1; i < tmp.length(); i++)
            tmp[i] = tolower(tmp[i]);

        answer += tmp + " ";
    }

    if(s[s.length() - 1] != ' ')
        answer.erase(answer.end() - 1);

    return answer;
}

int main()
{
    cout << solution("3people unFollowed me") << endl;
}


/*  best answer

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}
*/