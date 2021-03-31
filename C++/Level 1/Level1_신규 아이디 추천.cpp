#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    vector<char> id;
    // 벡터로 문자 분할
    for (auto i : new_id) {
        id.push_back(i);
    }
    string answer = "";
    string possibleChar = "1234567890abcdefghijklmnopqrstuvwxyz-_."; // 가능한 문자

    // 1단계
    for (int i = 0; i < id.size(); i++) {
        id[i] = tolower(id[i]);
    }

    // transform(id.cbegin(), id.cend(), id.begin(), tolower);
    
    // 2단계
    for (int i = 0; i < id.size(); i++){
        if (possibleChar.find(id[i]) == string::npos) {
            id.erase(id.begin() + i);
            i--;
        }
    }
    // 3단계
    for (int i = 0; i < id.size() - 1; i++) {
        if (id[i] == '.' && id[i+1] == '.') {
            id.erase(id.begin() + i);
            i--;
        }
    }
    // 4단계
    if (!id.empty()) {
        if (id.front() == '.')
            id.erase(id.begin());
    }
    if (!id.empty()) {
        if (id.back() == '.')
            id.pop_back();
    }
    // 5단계
    if (id.empty())
        id.push_back('a');
    // 6단계
    if (id.size() > 15) {
        while (id.size() > 15)
            id.pop_back();
        if (id.back() == '.')
            id.pop_back();
    }
    // 7단계
    if (id.size() < 3) {
        while (id.size() < 3)
            id.push_back(id.back());
    }
    // 문자열로 합치기
    for (auto i : id) {
        answer += i;
    }

    return answer;
}

int main() {

    cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("=.=") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;

    return 0;
}