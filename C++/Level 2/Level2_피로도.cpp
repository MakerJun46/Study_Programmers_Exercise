#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int k_tmp = k;
        int n_tmp = 0;

        for (int i = 0; i < dungeons.size(); i++)
        {
            if (k_tmp < dungeons[i][0] || k_tmp < dungeons[i][1])
                continue;
        
            k_tmp -= dungeons[i][1];
            n_tmp++;
        }

        if (answer < n_tmp)
            answer = n_tmp;

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

int main()
{
    cout << solution(80, { {80, 20}, {50, 40}, {30, 10} });
}