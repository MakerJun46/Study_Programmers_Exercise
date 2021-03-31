#include <string>
#include <vector>
#include "library.h"

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int LCM = 1; // Lowest common multiple
    int GCD = 1; // Greatest common measure
    int max, min, tmp;

    max = std::max(n, m);
    min = std::min(n, m);
    
    while (min != 0) {
        tmp = max % min;
        max = min;
        min = tmp;
    }
    GCD = max;

    LCM = n * m / GCD;

    answer.push_back(GCD);
    answer.push_back(LCM);

    return answer;
}

int main() {

    for (auto i : solution(5, 2)) {
        cout << i << " ";
    }

    return 0;
}