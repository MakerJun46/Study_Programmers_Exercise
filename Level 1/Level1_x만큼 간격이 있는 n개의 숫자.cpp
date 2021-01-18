#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long num = x;
    long long tmp = x;

    for (int i = 0; i < n; i++) {
        answer.push_back(num);
        num += tmp;
    }

    return answer;
}

int main() {


    return 0;
}