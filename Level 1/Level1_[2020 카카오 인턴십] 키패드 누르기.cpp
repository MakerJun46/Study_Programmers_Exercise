#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> dial;

    for (int i = 0; i < 4; i++) { // 좌표 입력
        for (int j = 0; j < 3; j++) {
            dial.push_back(pair<int, int>(j, i));
        }
    }

    int leftHandPosition = 10; // *
    int rightHandPosition = 12; // #

    for (auto i : numbers) {
        if (i == 3 || i == 6 || i == 9) { // 오른손
            rightHandPosition = i;
            answer += "R";
        }
        else if (i == 1 || i == 4 || i == 7) { // 왼손
            leftHandPosition = i;
            answer += "L";
        }
        else { // 2,5,8,0 의 경우, 0은 11로 간주한다.
            if (i == 0) i = 11;
            int leftDistance = abs(dial[leftHandPosition - 1].first - dial[i - 1].first) 
                + abs(dial[leftHandPosition - 1].second - dial[i - 1].second);   // 좌표 계산 |x1 - x2| + |y1 - y2|
            int rightDistance = abs(dial[rightHandPosition - 1].first - dial[i - 1].first)
                + abs(dial[rightHandPosition - 1].second - dial[i - 1].second);

            if (leftDistance == rightDistance) { // 거리가 같은 경우(손 확인)
                hand == "right" ? rightHandPosition = i : leftHandPosition = i;
                hand == "right" ? answer += "R" : answer += "L";
            }
            else if (leftDistance < rightDistance) { // 왼손이 더 가까운 경우
                leftHandPosition = i;
                answer += "L";
            }
            else { // 오른손이 더 가까운 경우
                rightHandPosition = i;
                answer += "R";
            }
        }
    }
    return answer;
}


int main() {
    string answer = solution({ 1,3,4,5,8,2,1,4,5,9,5 }, "right");

    cout << endl;
    cout << answer;

    return 0;
}