#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    int tmp;

    while (n > 2) {
        tmp = n % 3;
        num.push_back(tmp);
        n /= 3;
    }
    num.push_back(n);

    for (int i = num.size() - 1; i >= 0; i--) {
        answer += num[i] * pow(3, num.size() - 1 - i);
    }

    return answer;
}


int main() {
    cout << solution(125);
}