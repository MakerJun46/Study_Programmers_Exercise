#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long tmp = sqrt(n);

    if (tmp * tmp == n) {
        answer = powl(tmp + 1, 2);
    }
    else
        answer = -1;
   
    return answer;
}

int main() {

    cout << solution(100);

    return 0;
}