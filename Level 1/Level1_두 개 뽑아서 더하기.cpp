#include <vector>
#include <algorithm>
#include <string>

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
    printf("%s", solution({ "leo", "kiki", "eden" }, { "eden", "leo" }));

    return 0;
}
