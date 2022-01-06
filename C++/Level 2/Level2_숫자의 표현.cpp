#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;

    for (int i = 1; i < n / 2 + 1; i++)
    {
        int sum_tmp = 0;

        for (int j = i;; j++)
        {
            sum_tmp += j;
            
            if (sum_tmp == n)
                answer++;
            else if (sum_tmp > n)
                break;
        }
    }

    return answer;
}

int main()
{
    cout << solution(15) << endl;
}