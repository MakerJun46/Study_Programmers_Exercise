#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    string answer = "";

    map<string, int> number_words;
    number_words.insert(make_pair("zero", 0));
    number_words.insert(make_pair("one", 1));
    number_words.insert(make_pair("two", 2));
    number_words.insert(make_pair("three", 3));
    number_words.insert(make_pair("four", 4));
    number_words.insert(make_pair("five", 5));
    number_words.insert(make_pair("six", 6));
    number_words.insert(make_pair("seven", 7));
    number_words.insert(make_pair("eight", 8));
    number_words.insert(make_pair("nine", 9));

    string str_tmp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            answer += stoi(to_string(s[i]));
        }
        else
        {
            str_tmp += s[i];
            auto confirm = number_words.find(str_tmp);
            if (confirm != number_words.end())
            {
                answer += to_string(confirm->second);
                str_tmp = "";
            }
        }
    }

    return stoi(answer);
}

int main()
{
    solution("8nine6zero1");
}