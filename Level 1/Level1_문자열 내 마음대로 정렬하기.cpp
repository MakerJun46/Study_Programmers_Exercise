#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

bool compareChar(string left, string right) {
    if (left.at(N) != right.at(N))
        return  left.at(N) < right.at(N);
    else
        return left < right;
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), compareChar);
    return answer;
}

/* Best answer
int i;

bool compare (string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort (strings.begin(), strings.end(), compare);
    return strings;
}
*/



int main() {
    
    vector<string> answer = solution({ "sun", "abcd", "abce","bed", "cdx" ,"car"}, 2);

    cout << "==============\n";
    for(auto i : answer){
        cout << i << endl;
    }
}