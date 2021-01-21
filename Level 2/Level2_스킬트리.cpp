#include <string>
#include <vector>
#include "library.h"

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skill_Index;
    
    for (int i = 0; i < skill_trees.size(); i++) {
        for (int j = 0; j < skill.size(); j++) {
            int index = skill_trees[i].find(skill[j]);
            skill_Index.push_back(skill_trees[i][index]);
        }
        if (skill_Index.empty()) {
            answer++;
            continue;
        }
        bool isPossible = true;
        for (int j = 0; j < skill_Index.size(); j++) {
            if (skill[j] != skill_Index[j]) {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
            answer++;
        skill_Index.clear();
    }
    return answer;
}

int main() {

    cout << solution("CBD", { "CAD" }); // 0
    cout << solution("CBD", { "AEF", "ZJW" }); // 2
    cout << solution("REA", { "REA", "POA" }); // 1
    cout << solution("CBDK", { "CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK" }); // 4
    cout << solution("BDC", { "AAAABACA" }); // 0
    cout << solution("CBD", { "C", "D", "CD", "BDA" }); // 2

    return 0;
}