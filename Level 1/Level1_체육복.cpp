#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    for(int i = 0; i < n; i++){
        student.push_back(1);
    }
    for (auto i : lost) {
        student[i-1]--;
    }
    for (auto i : reserve) {
        student[i-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (student[i] == 0) {
            if (student[i + 1] == 2) {
                student[i + 1]--;
                student[i]++;
            }
            else if (i != 0 && student[i - 1] == 2) {
                student[i - 1]--;
                student[i]++;
            }
        }
    }
    for (auto i : student) {
        if (i > 0)
            answer++;
    }
    return answer;
}


int main() {

    cout << solution(5, { 2,4 }, { 1,3,5 });

    return 0;
}