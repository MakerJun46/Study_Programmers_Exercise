#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);

    map<string, int> wordsMap;

    wordsMap[words[0]]++;
    string tmp = words[0];

    for (int i = 1; i < words.size(); i++)
    {
        wordsMap[words[i]]++;
        if (tmp[tmp.length() - 1] != words[i][0] || wordsMap[words[i]] == 2) // 끝말잇기에서 틀린 경우
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        else
            tmp = words[i];
    }

    return answer;
}

int main()
{
    vector<int> answer;
    vector<string> words
    {
        "hello", "one", "even", "never", "now", "world", "draw"
    };

    set<string> s;

    s.insert("abc").second

    answer = solution(2, words);

    for (auto i : answer)
    {
        cout << i << endl;
    }
}