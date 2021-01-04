#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (auto i : arr) {
        if (i % divisor == 0) {
            answer.push_back(i);
        }
    }
    if (answer.empty()) return { -1 };
    else
        sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<int> answer = solution({ 2,36,1,3 }, 1);

    for (auto i : answer) {
        cout << i << " ";
    }

}