#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long tmp = 0;

    for (int i = 1; i < count + 1; i++)
    {
        tmp += price * i;
    }

    return money - tmp < 0 ? -(money-tmp) : 0;
}

int main()
{
    cout << solution(3, 20, 4);
}

/*  best answer
long long solution(int price, int money, int count)
{
    long long required = 1LL * price * count * (count + 1) / 2; // 1부터 n까지의 합 * price
    return required <= money ? 0 : required - money;
}
*/