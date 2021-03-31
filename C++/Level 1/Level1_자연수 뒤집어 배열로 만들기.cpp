#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string sTmp = to_string(n);
    
    for (auto i : sTmp) {
        answer.push_back(atoi(&i));
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

/* mathmatic solve
* vector<int> solution(long long n) {
    vector<int> answer;
    while(n){
        answer.push_back(n%10);
        n/=10;
    }
    return answer;
}
*/

int main() {

    for (auto i : solution({ 13524 })) {
        cout << i << " ";
    }

    return 0;
}
