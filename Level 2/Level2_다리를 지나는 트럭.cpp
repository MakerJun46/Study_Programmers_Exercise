#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<pair<int, int>> truck_passing;
    int weightSum = 0;
    int time = 0;

    while (true) {
        time++;
        if (truck_passing.empty() && truck_weights.empty())
            break;
        if (!truck_weights.empty() && weightSum + truck_weights[0] <= weight) {
            weightSum += truck_weights[0];
            truck_passing.push_back(make_pair(0, truck_weights[0]));
            truck_weights.erase(truck_weights.begin());
        }
        for (int i = 0; i < truck_passing.size(); i++) {
            truck_passing[i].first++;
        }
        if (truck_passing[0].first == bridge_length) {
            weightSum -= truck_passing[0].second;
            truck_passing.erase(truck_passing.begin());
        }
    }

    return time;
}

int main() {
    cout << solution(2, 10, { 7,4,5,6 });
    cout << endl;
    cout << solution(100, 100, { 100 });
    cout << endl;
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });

    return 0;
}