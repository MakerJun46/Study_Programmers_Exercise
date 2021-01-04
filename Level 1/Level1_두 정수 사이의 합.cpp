#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long max = (a > b ? a : b);
    long min = a < b ? a : b;

    if (max == min) return max;

    for (long i = min; i <= max; i++) {
        answer += i;
    }

    return answer;
}

int main() {
    cout << solution(5, 3);
}