#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

    for (int i = 0; i < priorities.size(); i++) {
        for (int j = i; j < priorities.size(); j++) {
            if (priorities[i] < priorities[j]) {
                if (location == i) 
                    location = priorities.size() - 1;
                else if (location > i) 
                    location--;
                priorities.push_back(priorities[i]);
                priorities.erase(priorities.begin() + i);
                i--;
                break;
            }
        }
    }

    int answer = location + 1;

    return answer;
}

int main() {

    cout << solution({2,1,3,2}, 2) << endl;
    cout << solution({1,1,9,1,1,1}, 0);
    

    return 0;
}