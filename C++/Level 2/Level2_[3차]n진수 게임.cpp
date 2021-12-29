#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string conversion(int n, int number)
{
    string converse = "";

    if (number == 0)
        return "0";

    while (number > 0)
    {
        if (number % n < 10)
            converse += to_string(number % n);
        else
            converse += char(number % n - 10 + 'A');

        number /= n;
    }
    reverse(converse.begin(), converse.end());

    return converse;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string tmp;
    int number = 0;

    for (int i = 0; i < t; i++)
    {
        while (tmp.length() < m)
        {
            tmp += conversion(n, number++);
        }

        answer += tmp[p - 1];

        tmp = tmp.length() > m ? tmp.substr(m) : "";
    }

    return answer;
}

int main()
{
    cout << solution(2, 6, 2, 1) << endl;
    cout << solution(16, 16, 2, 1) << endl;
    cout << solution(16, 16, 2, 2) << endl;
}