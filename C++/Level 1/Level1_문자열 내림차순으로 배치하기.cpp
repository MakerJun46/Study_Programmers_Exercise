#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> sTmp;

    for (int i = 0; i < s.length(); i++) {
        sTmp.push_back(s[i]);
    }

    sort(sTmp.begin(), sTmp.end(), greater<char>());

    for (auto i : sTmp) {
        answer += i;
    }

    return answer;
}

/* Best Answer
 string solution(string s) {
    sort (s.begin(), s.end(), greater<char>());
    return s;
}
*/


int main() {
    
    string s = "Zbcdefg";

    cout << solution(s);

    return 0;
}