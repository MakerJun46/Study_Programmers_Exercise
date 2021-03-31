#include <string>
#include <vector>
#include <iostream>

using namespace std;

int grading(vector<int> answers, vector<int> p, int n) {
    int index;
    int count = 0;

    for (int i = 0; i < answers.size(); i++) {
        index = i % n;
        if (answers[i] == p[index]) {
            count++;
        }
    }
    return count;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> p1 = { 1,2,3,4,5 };
    vector<int> p2 = { 2,1,2,3,2,4,2,5 };
    vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };
  
    int grades[3] = { grading(answers, p1, 5), grading(answers, p2, 8), grading(answers, p3, 10) };
    int max = grades[0];

    for (int i = 1; i < 3; i++) {
        if (max < grades[i])
            max = grades[i];
    }

    for (int i = 0; i < 3; i++) {
        if (max == grades[i])
            answer.push_back(i + 1);
    }

    return answer;
}

int main() {
    vector<int> answers; // 정답 목록 (1~ 10,000 문제)
    vector<int> answer = solution(answers);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}