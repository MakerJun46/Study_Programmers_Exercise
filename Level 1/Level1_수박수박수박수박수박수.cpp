#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++) {
        answer += i % 2 ? "박" : "수";
    }

    return answer;
}

int main() {
    cout << solution(3);
    return 0;
}