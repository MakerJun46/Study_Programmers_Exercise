#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


/*      O(n) 의 코드
int main(void) {
    int a;
    int b;
    cin >> a >> b;

    string s;

    s.append(a, '*');

    for (int i = 0; i < b; ++i)
    {
        cout << s << endl;
    }
    return 0;
}

*/