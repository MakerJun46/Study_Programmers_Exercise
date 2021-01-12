#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> tmp;
    
    while (n > 0) {
        tmp.push_back(n % 10);
        n /= 10;
    }

    sort(tmp.rbegin(), tmp.rend());
    
    n = 1;
    while (!tmp.empty()) {
        answer += tmp.back() * n;
        tmp.pop_back();
        n *= 10;
    }

    return answer;
}


/*  Best Answer
* long long solution(long long n) {
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}
*/

int main() {
    

    return 0;
}