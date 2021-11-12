#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> larger_sizes;
    vector<int> smaller_sizes;

    for (int i = 0; i < sizes.size(); i++)
    {
        sizes[i][0] > sizes[i][1]? larger_sizes.push_back(sizes[i][0]), smaller_sizes.push_back(sizes[i][1])
            : (larger_sizes.push_back(sizes[i][1]), smaller_sizes.push_back(sizes[i][0]));

        /*
        if (sizes[i][0] >= sizes[i][1])
        {
            larger_sizes.push_back(sizes[i][0]);
            smaller_sizes.push_back(sizes[i][1]);
        }
        else
        {
            larger_sizes.push_back(sizes[i][1]);
            smaller_sizes.push_back(sizes[i][0]);
        }
        */
    }

    answer = *max_element(larger_sizes.begin(), larger_sizes.end()) * *max_element(smaller_sizes.begin(), smaller_sizes.end());

    return answer;
}

int main()
{
    cout << solution({ {60, 50}, {30, 70}, {60, 30}, {80, 40} });
}

/*  best answer
int solution(vector<vector<int>> sizes)
{
    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));  // 작은 값 중에 가장 큰 값
        h=max(h,max(sizes[i][0],sizes[i][1]));  // 큰 값 중에 가장 큰 값
    }
    answer=w*h;

    return answer;
}
*/