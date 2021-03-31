#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;

    for (auto i : arr1) {
        map1.push_back(bitset<16>(i).to_string());
    }
    for (auto i : arr2) {
        map2.push_back(bitset<16>(i).to_string());
    }

    answer.resize(n, "");

    for (int i = 0; i < n; i++) {
        for (int j = map1[i].size() - n; j < map1[i].size(); j++) {
            answer[i] += ((map1[i][j] == '1' || map2[i][j] == '1') ? "#" : " ");
        }
    }

    return answer;
}

/*   Best Answer
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}

*/


int main() {
    vector<string> answer = solution(5, { 9, 20, 28,18,11 }, { 30,1,21,17,28 });

    for (auto i : answer) {
        cout << i << endl;
    }
}