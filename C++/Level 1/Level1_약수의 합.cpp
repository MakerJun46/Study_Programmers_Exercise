#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
        }
    }
    return answer;
}
/* Best Answer
int sumDivisor(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) if (n % i == 0) { sum += i; if (n != i * i) sum += n / i; }
    return sum;
}
*/

int main() {

    cout << solution(5);


    return 0;
}