#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (auto i : s) {
        int tmp = (int)i;
        if (65 <= tmp && tmp <= 90) {
            tmp += n;
            if (tmp > 90)
                tmp -= 26;
        }
        else if (97 <= tmp && tmp <= 122) {
            tmp += n;
            if (tmp > 122)
                tmp -= 26;
        }
        answer += (unsigned char)tmp;
    }

    return answer;
}

int main() {

    cout << solution("AB", 1) << endl;
    cout << solution("z", 1) << endl;
    cout << solution("a B z", 4) << endl;
    cout << solution("AaZz", 25);


    return 0;
}