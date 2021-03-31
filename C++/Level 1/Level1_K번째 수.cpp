#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> vecTmp;
    
    for (auto i : commands) {
        for (int j = i[0] - 1; j < i[1]; j++) {
            vecTmp.push_back(array[j]);
        }
        sort(vecTmp.begin(), vecTmp.end());

        answer.push_back(vecTmp[i[2] - 1]);
        vecTmp.clear();
    }

    return answer;
}

int main() {

    vector<int>array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };

    vector<int>answer = solution(array, commands);

    for(auto i : answer)
    {
        cout << i << " ";
    }

    return 0;
}