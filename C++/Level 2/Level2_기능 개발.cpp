#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while (!progresses.empty()) {
        for (int i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 100) {
                progresses[i] += speeds[i];
            }
        }
        int tmp = 0;
        while(!progresses.empty()){
            if (progresses[0] >= 100) {
                tmp++;
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
            }
            else
                break;
        }
        
        if (tmp) {
            answer.push_back(tmp);
        }
    }

    return answer;
}

/*      Best Answer
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}
*/

int main() {

    
    for (auto i : solution({ 93, 30, 55 }, { 1, 30, 5 })) {
        cout << i << " ";
    }


    for (auto i : solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1,1,1,1,1 })) {
        cout << i << " ";
    }

    return 0;
}