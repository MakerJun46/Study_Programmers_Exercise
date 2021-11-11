#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_factor_Even_number(int a)
{
    int count = 0;

    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            count++;
        }
    }

    return !(count & 1);
}


int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        answer += is_factor_Even_number(i) ? i : i * -1;
    }

    return answer;
}

int main()
{

}