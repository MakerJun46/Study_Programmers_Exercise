#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0); // 0 : 반복 횟수 , 1 : 제거한 0 개수

    while (s != "1")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                s.erase(s.find('0'), 1);
                i--;
                answer[1]++;
            }
        }

        bitset<150000> bs(s.length());
        string tmp = bs.to_string();
        s = tmp.substr(tmp.find('1'));
        
        answer[0]++;
    }

    return answer;
}

void main()
{
    vector<int> answer = solution("110010101001");

    for (auto i : answer)
    {
        cout << i << endl;
    }
}