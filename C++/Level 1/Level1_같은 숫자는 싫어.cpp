#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    int answerIndexCount = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != answer[answerIndexCount]) {
            answer.push_back(arr[i]);
            answerIndexCount++;
        }
    }

    return answer;
}

/* bestAnswer
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end()); 
    // unique(*startpoint, endpoint)=> 시작 지점부터 끝 지점까지 중복 요소를 벡터 밖으로 밀어낸다.
    // 작업 후 return은 밀어낸 요소들의 시작점이므로
    // erase(unique(...), arr.end()), arr.end());는 밀어낸 값을 삭제하는 코드

    vector<int> answer = arr;
    return answer;
}
*/

int main() {

    for (auto i : solution({ 4,4,4,3,3 })) {
        cout << i << " ";
    }

}