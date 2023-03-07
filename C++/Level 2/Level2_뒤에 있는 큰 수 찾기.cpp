#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> bbigNumIdx(numbers.size(), -1);

    reverse(numbers.begin(), numbers.end());
    answer.push_back(-1);

    for (int i = 1; i < numbers.size(); i++)
    {
        int idx = i - 1;

        while(idx != -1)
        {
            if (numbers[i] < numbers[idx])
            {
                bbigNumIdx[i] = idx;
                answer.push_back(numbers[idx]);
                break;
            }
            else
            {
                idx = bbigNumIdx[idx];
            }
        }

        if (idx == -1)
            answer.push_back(-1);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

void main()
{
    auto answer =  solution({ 9, 1, 5, 3, 6, 2 });

    for(int var : answer)
    {
        cout << var << endl;
    }
}