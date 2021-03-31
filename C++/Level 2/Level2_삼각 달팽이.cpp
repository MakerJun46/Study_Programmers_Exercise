#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> position(n, vector<int>(n));
    int x = 0;
    int y = -1;
    int k = 0;
    int count = 0;

    while (n >= 0) {
        k++;
        if (k % 3 == 1) { // 내려가는 +
            for (int i = 0; i < n; i++) {
                y++;
                count++;
                position[x][y] = count;
            }
        }
        else if (k % 3 == 2) {
            for (int i = 0; i < n; i++) {
                x++;
                count++;
                position[x][y] = count;;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                x--;
                y--;
                count++;
                position[x][y] = count;
            }
        }
        n--;
    }

    for (int i = 0; i < position.size(); i++) {
        for (int j = 0; j < position.size(); j++) {
            if (position[j][i] != NULL) {
                answer.push_back(position[j][i]);
            }
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