#include <iostream>
#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;
    string s = to_string(n);
    
    for (auto i : s) {
        answer = answer + atoi(&i);
    }

    return answer;
}


/* mathmatic solve
int solution(int n)
{
    int answer = 0;
    while (n > 0) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}
*/

int main() {

    cout << solution(123456);

    return 0;
}