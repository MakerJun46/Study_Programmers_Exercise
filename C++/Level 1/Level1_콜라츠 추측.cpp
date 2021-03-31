#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    bool isAnswer = false;

    while (!isAnswer) {
        if (n == 1) {
            isAnswer = true;
            break;
        }
        if (answer == 500) {
            answer = -1;
            break;
        }
        
        if ((n & 1) == 1) {
            n = n * 3 + 1;
        }
        else {
            n = n / 2;
        }
        answer++;
    }

    return answer;
}

int main() {

    cout << solution(626331);

    return 0;
}