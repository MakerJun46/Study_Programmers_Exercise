#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> numbers;

    stringstream ss(s);
    string tmp;

    while (getline(ss, tmp, ' '))
    {
        numbers.push_back(stoi(tmp));
    }

    int max = *max_element(numbers.begin(), numbers.end());
    int min = *min_element(numbers.begin(), numbers.end());

    answer += to_string(min) + " " + to_string(max);

    return answer;
}


int main()
{
    cout << solution("1 2 3 4") << endl;
    cout << solution("-1 -2 -3 -4") << endl;
}