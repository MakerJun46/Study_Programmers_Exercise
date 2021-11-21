#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto i : scoville)
    {
        pq.push(i);
    }

    while (true)
    {
        if (pq.top() >= K)
        {
        break;
        }
        else if (pq.size() == 1 && pq.top() < K)
        {
            return -1;
        }

        int min_scoville = pq.top();
        pq.pop();
        int next_scoville = pq.top();
        pq.pop();

        pq.push(min_scoville + next_scoville * 2);

        answer++;
    }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };

    vector<int> test = { 30, 1, 50, 99, 2, 4 };

    cout << solution(scoville, 7) << endl;
}



/*
while (true)
{
    sort(scoville.begin(), scoville.end());
    if (scoville.size() == 1 && scoville[0] < K)
    {
        return -1;
    }
    else if (scoville[0] >= K)
    {
        break;
    }
    scoville[1] = scoville[0] + scoville[1] * 2;
    scoville.erase(scoville.begin());
    answer++;
}
*/