#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second) {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
    else
        return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> stageFailRate;
    vector<pair<int, double>> stageCount;

    sort(stages.rbegin(), stages.rend());

    for (int i = 1; i <= N; i++) {
        int userPassStage = 0;
        int userNowPlayingStage = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] < i) break;
            if (stages[j] >= i) userPassStage++;
            if (stages[j] == i) userNowPlayingStage++;
        }
        double failRate;
        if (userPassStage == 0)
            failRate = 0;
        else
            failRate = (double)userNowPlayingStage / userPassStage;
        stageCount.push_back(make_pair(i, failRate));
    }

    sort(stageCount.begin(), stageCount.end(), compare);
    for (auto i : stageCount) {
        stageFailRate.push_back(i.first);
    }

    return stageFailRate;
}


int main() 
{
    vector<int> answer = solution(5, { 2,1,2,6,2,4,3,3 });

    for (auto i : answer) {
        cout << i << " ";
    }

    return 0;
}