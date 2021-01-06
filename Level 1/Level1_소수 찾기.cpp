#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == false) {
            continue;
        }
        for (int j = i + i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            answer++;
        }
    }

    return answer;
}

/*     Best Answer
int solution(int n) {
    int answer = 0;
    vector<bool> tmp(n+1, true);

    for (int i=2; i<n+1; i++) {
        if (tmp[i] == true) {
            for (int j=2; i*j<n+1; j++) 
                tmp[i*j] = false;
            answer++;
        }
    }

    return answer;
}
*/

int main() {
    
    cout << solution(10);

    return 0;
}

