#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) { // 유클리드 호제법
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    answer = (long long)w * (long long)h - (w + h - gcd(w, h)); // 이걸 어케 생각해..
    return answer;
}

int main() {

    cout << solution(8, 12) << endl;
    cout << solution(3, 3) << endl;

    return 0;
}