#include <string>
#include <vector>
#include "library.h"

using namespace std;

int solution(string s) {
    int answer = s.size(); // default

    if (s.length() == 1)
        return 1;

    for (int i = 1; i < s.length() / 2; i++) 
    {
        int count = 1;
        string cmpSt = s.substr(0, i);
        string cmp, cp;

        for (int j = i; j < s.length(); j += i)
        {
            cmp = s.substr(j, i);

            if (cmpSt == cmp) 
            {
                count++;
            }
            else
            {
                if (count == 1)
                {
                    cp += cmpSt;
                    cmpSt = cmp;
                }
                else
                {
                    cp = cp + to_string(count) + cmpSt;
                }
            
            }
        
        }

    }


    /*
    for (int i = 1; i <= s.length() / 2; i++)
    {
        int count = 1;
        string f = s.substr(0, i);
        string cmp, cp;

        for (int j = i; j < s.length(); j += i) 
        {
            cmp = s.substr(j, i);

            if (!(f.compare(cmp))) // 비교 문자가 같으면 count 증가
                count++;
            else
            {
                if (count == 1)
                {
                    cp += f;
                    f = cmp;
                }
                else
                {
                    cp = cp + to_string(count) + f;
                    f = cmp;
                    count = 1;
                }
            }

            if (j + i >= s.length()) // 마지막에 substr 기준을 초과한 경우
            {
                if (count != 1)
                {
                    cp = cp + to_string(count) + f;
                    break;
                }
                else
                {
                    cp = cp + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > cp.length()) ? cp.length() : answer;
    }
    

    */
    return answer;
}

int main() {
    
    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcdede") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd") << endl;

    return 0;
}