#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skill_index;

    for (int i = 0; i < skill_trees.size(); i++) {
        for (auto j : skill_trees[i]) {
            int tmp = skill.find(j);
            if(tmp != string::npos)
                skill_index.push_back(skill[tmp]);
        }
        if (skill_index.empty()) {
            answer++;
            continue;
        }
        bool isPossible = true;
        for (int j = 0; j < skill_index.size(); j++) {
            if (skill[j] != skill_index[j]) {
               isPossible = false;
               break;
            }
        }
        if (isPossible) {
            answer++;
        }
        skill_index.clear();
    }
    return answer;
}

int main() {

    cout << solution("CBD", { "CAD" }); // 0
    cout << solution("CBD", { "AEF", "ZJW" }); // 2
    cout << solution("REA", { "REA", "POA" }); // 1
    cout << solution("CBDK", { "CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK" }); // 4
    cout << solution("BDC", { "AAAABACA" }); // 0
    cout << solution("CBD", { "C", "D", "CD", "BDA" }); // 1

    return 0;
}