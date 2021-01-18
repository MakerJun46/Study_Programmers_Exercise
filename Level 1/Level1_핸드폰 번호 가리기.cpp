#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    for (auto i : arr) {
        answer += i;
    }

    return answer / arr.size();
}

int main() {

    cout << solution({ 1,2,3,4 });

    return 0;
}
