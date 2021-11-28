#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int max_Round = 1;

    int big_n;
    int small_n;

    a > b ? big_n = a, small_n = b : (small_n = a, big_n = b);

    while(true)
    {
        if (round((float)big_n / 2.0) == round((float)small_n / 2.0))
            break;

        big_n = round((float)big_n / 2.0);
        small_n = round((float)small_n / 2.0);

        answer++;
    }

    return answer;
}


int main()
{
    cout << solution(8, 4, 5) << endl;
}