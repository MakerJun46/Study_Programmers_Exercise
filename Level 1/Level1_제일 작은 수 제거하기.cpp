#include <string>
#include <vector>
#include "library.h"

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int index = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[index])
            index = i;
    }

    arr.erase(arr.begin() + index);
    
    if (arr.empty())
        arr.push_back(-1);

    return arr;
}

/* Best Answer #include <algorithm>
vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());     // min_element( start it, end it ) => 최소값 탐색
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(answer.begin() + pos);

    return answer.empty() ? vector<int>(1, -1) : answer;
}

*/


int main() {
    for (auto i : solution({ 4,3,2,1 })) {
        cout << i << " ";
    }

    cout << endl;

    for (auto i : solution({ 10 })) {
        cout << i << " ";
    }

    return 0;
}