#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    while (answer != n)
    {
        answer++;
        if (n % answer == 1)
            break;
    }


    return answer;
}