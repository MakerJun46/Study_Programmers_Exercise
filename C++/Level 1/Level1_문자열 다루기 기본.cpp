#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;

    for (auto i : s) {
        if (!(47 < (int)i && (int)i < 58)) 
            return false;
    }
    if (s.length() == 4 || s.length() == 6)
        return answer;
    else
        return false;
}

/* Best Answer
* bool solution(string s) {
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}

*/

int main() {
    cout << solution("a234") << "\n";
    cout << solution("1234");

    

}