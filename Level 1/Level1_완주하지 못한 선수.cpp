#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }

    return participant[participant.size() - 1];
}

int main() {

    cout << solution({ "leo", "kiki", "eden" }, { "leo", "eden" });

    return 0;
}
