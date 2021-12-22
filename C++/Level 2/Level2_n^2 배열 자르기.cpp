#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        int a = i / n;
        int b = i % n;
        answer.push_back(a < b ? b + 1 : a + 1);
    }

    return answer;
}

int main()
{
    vector<int> answer = solution(3, 2, 5);

    cout << endl << "answer size : " << answer.size() <<  endl;
    for (auto i : answer)
    {
        cout << i << endl;
    }
}

/* best answer
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int row;
    int column;
    for(long long i = left; i <= right; i++){
        answer.push_back(max(i / n, i % n) + 1);
    }

    return answer;
}
*/