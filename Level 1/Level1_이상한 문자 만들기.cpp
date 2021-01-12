#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 1;

    for (auto i : s) {
        int tmp = (int)i;
        if (tmp == (int)' ') {
            count = 1;
            answer += ' ';
            continue;
        }
        if (islower(i) && (count&1)) { // 소문자고 홀수 자리라면
            tmp -= 32;
        }
        else if (!islower(i) && !(count&1)) { // 대문자고 짝수 자리라면
            tmp += 32;
        }
        answer += (unsigned char)tmp;
        count++;
    }

    return answer;
}

/* Best Answer
* string solution(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);  // toupper, tolower 사용
    }

    return answer;
}
*/


int main() {

    cout << solution("try hello world");

    return 0;
}