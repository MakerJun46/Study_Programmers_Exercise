#include <string>
#include <vector>
#include "library.h"

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> stair(n + 1);
    int count = 1;
    int stairIndex = 0;
    vector<int>::iterator itLeft;

    for (int k = 1; k > 0; k++) {
        if (n <= 0) {
            break;
        }
        if (k % 3 == 1) {
            for (int i = 0; i < n; i++) {
                stairIndex++;
                stair[stairIndex].insert(indexLeft[stairIndex], count);
                indexLeft[stairIndex] ++;
                count++;
            }
            n--;
        }
        else if (k % 3 == 2) {
            for (int i = 0; i < n; i++) {
                stair[stairIndex].insert(indexLeft[stairIndex]++,count);
                count++;
            }
            n--;
        }
        else {
            for (int i = 0; i < n; i++) {
                stairIndex--;
                stair[stairIndex].insert(indexRight[stairIndex]--, count);
                count++;
            }
            n--;
        }
    }

    for (auto i : stair) {
        for (auto j : i) {
            answer.push_back(j);
        }
    }

    return answer;
}

int main() {

    for (auto i : solution(6)) {
        cout << i << " ";
    }

    return 0;
}