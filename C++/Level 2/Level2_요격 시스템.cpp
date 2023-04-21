#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), cmp);

    while (!targets.empty())
    {
        vector<int> thisValue = targets.front();

        int endValue = thisValue[1];
        int range = 0;

        while (range < targets.size())
        {
            vector<int> nextValue = targets.at(range);

            if (endValue <= nextValue[0])
            {
                break;
            }

            range++;
        }

        targets.erase(targets.begin(), targets.begin() + range);

        answer++;
    }

    return answer;
}

int main()
{
    cout << solution({ {0, 4 }, {0, 1}, {2, 3}});
}