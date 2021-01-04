#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int countP, countY;
    countP = countY = 0;

    for (auto i : s) {
        if (i == 'p' || i == 'P')
            countP++;
        if (i == 'y' || i == 'Y')
            countY++;
    }
    if (countP != countY)
        return false;

    return answer;
}

int main() {
    solution("pPooooyY");
}