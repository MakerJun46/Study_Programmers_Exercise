#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;

    stringstream ss(s);

    vector<string> numbers;
    string tmp;
    while (getline(ss, tmp, ','))
    {
        numbers.push_back(tmp);
    }

    map<string, int> count;

    for (string s : numbers)
    {
        tmp = "";
        for (char c : s)
        {
            if (isdigit(c))
                tmp += c;
        }
        count[tmp]++;
    }

    vector<pair<string, int>> count_vec(count.begin(), count.end());

    sort(count_vec.begin(), count_vec.end(), cmp);

    for (auto i : count_vec)
    {
        answer.push_back(stoi(i.first));
    }

    return answer;
}

void main()
{
    vector<int> answer = solution("{{20, 111}, {111}}");

    for (auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;

}