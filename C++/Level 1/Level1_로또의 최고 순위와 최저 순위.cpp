#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int worstRate = 7;
    int bestRate = 7;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            bestRate--;
        }
        else
        {
            auto it = find(win_nums.begin(), win_nums.end(), lottos[i]);
            if (it != win_nums.end())
            {
                bestRate--;
                worstRate--;
            }
        }
    }
    if (worstRate == 7)
    {
        worstRate = 6;
    }
    if (bestRate == 7)
    {
        bestRate = 6;
    }

    answer.push_back(bestRate);
    answer.push_back(worstRate);

    return answer;
}

int main()
{
    vector<int> lottos = { 0, 0, 0, 0, 0, 0 };
    vector<int> win_nums = { 38, 19, 20, 40, 15, 25 };

    vector<int> answer = solution(lottos, win_nums);

    cout << answer[0] << ", " << answer[1];
    return 0;
}