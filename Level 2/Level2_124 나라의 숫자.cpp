#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    char numbers[3] = { '4', '1', '2' }; // 3 이상은 자릿수가 올라가지 않고 4로 바뀌므로 0 대신 4로 계산

    while (n > 0) {
        answer = numbers[n % 3] + answer; 
        n = n / 3 - (n % 3 == 0); // 3의 배수 일 때 자릿수가 올라가지 않으므로 -1 해준다.
    }

    return answer;
}

int main() {

    cout << solution(10);

    return 0;
}