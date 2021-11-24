#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<int> Fibo;

    Fibo.push_back(0);
    Fibo.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        Fibo.push_back((Fibo[i - 1] + Fibo[i - 2]) % 1234567);
    }

    return *(Fibo.end() - 1) % 1234567;
}

void main()
{
    cout << solution(5) << endl;
}

