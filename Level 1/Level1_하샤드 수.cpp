#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(int x) {
    int num = x;
    int tmp = 0;
    /*
    string sTmp = to_string(x);

    for (int i = 0; i < sTmp.size(); i++)
    {
        tmp += sTmp[i] - 48;
    }

    for (auto i : sTmp) {
        tmp += i - 48;
    }

    for_each(sTmp.begin(), sTmp.end(), [&tmp](char& c) {tmp += c - 48; });
    */
    while (num != 0) {
        tmp += num % 10;
        num /= 10;
    }

    return x % tmp == 0;
}

int main() {

    return 0;
}