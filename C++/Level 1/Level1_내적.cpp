#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    for (int i = 0; i < a.size(); i++) {
        answer += (a[i] * b[i]);
    }

    return answer;
}

int main() {

    cout << solution({ -1,0,1 }, { 1, 0, -1 });

    return 0;
}