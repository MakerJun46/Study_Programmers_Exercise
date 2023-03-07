#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> dictionary;
vector<char> alpha = { 'A', 'E', 'I', 'O', 'U' };

void DFS(string word, int len)
{
    if (len == word.length())
    {
        dictionary.push_back(word);
        return;
    }
    for (int i = 0; i < alpha.size(); i++)
    {
        DFS(word + alpha[i], len);
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int len = 1; len <= 5; len++)
    {
        DFS("", len);
    }

    sort(dictionary.begin(), dictionary.end());
    
    answer = find(dictionary.begin(), dictionary.end(), word) - dictionary.begin();

    return answer + 1;
}

int main()
{
    cout << solution({ "E" });
}