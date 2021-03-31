#include <string>
#include <vector>

using namespace std;

string solution(int num) {

    return num & 1 ? "Odd" : "Even";
}

int main() {

    cout << solution(3) << endl;
    cout << solution(4);

    return 0;
}