#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(long long num) {
    if (num < 2) 
        return false;

    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) 
            return false;

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string n_k = "";

    while (n != 0)
    {
        int r = n % k;
        n = n / k;

        n_k += to_string(r);
    }

    reverse(n_k.begin(), n_k.end());

    string tmp = "";

    for (int i = 0; i < n_k.length(); i++)
    {
        if (n_k[i] == '0' && !tmp.empty())
        {
            if (isPrime(stoll(tmp)))
                answer++;
            tmp = "";
        }
        else
            tmp += n_k[i];
    }

    if (!tmp.empty() && isPrime(stoll(tmp)))
        answer++;

    return answer;
}

int main()
{
    //cout << solution(110011, 10) << endl;
    cout << solution(437674, 3) << endl;
}