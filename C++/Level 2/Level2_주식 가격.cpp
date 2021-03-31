#include <string>
#include <vector>
#include "library.h"

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {
        int sec = 0;
        for (int j = i; j < prices.size(); j++) {
            sec++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(sec - 1);
    }

    return answer;
}

/*      using Stack  - O(n)
* #include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

*/

int main() {

    for (auto i : solution({ 1,2,3,2,3 })) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : solution({ 5,8,6,2,4,1 })) {
        cout << i << " ";
    }

    return 0;
}