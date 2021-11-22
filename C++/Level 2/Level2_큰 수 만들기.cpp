#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


string solution(string number, int k) {

    string answer = "";

    for (int j = 0, index = -1; j < number.length() - k; j++)
    {
        char maxNum = 0;
        for (int i = index + 1; i <= k + j; i++)
        {
            if (maxNum < number[i])
            {
                index = i;
                maxNum = number[i];
            }
        }
        answer += maxNum;
    }

    return answer;
}

int main()
{
    //cout << solution("1924", 2) << endl;
    //cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}