#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    
    int answer = stoi(s); // string to int -> int stoi(string s)
                          // string to float -> float stof(string s)
    return answer;
}

int main() {

    cout << solution("-1234");

    return 0;
}