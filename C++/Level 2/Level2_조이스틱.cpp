#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    string nickname(name.length(), 'A');

    int index = 0;

    while (true)
    {
        nickname[index] = name[index];

        if (name[index] - 'A' > 'Z' + 1 - name[index])
        // 문자열의 처음부터 시작하는 것보다 끝에서 돌아오는게 더 빠른 경우
        {
            answer += 'Z' + 1 - name[index];
        }
        else
        // 문자열의 처음부터 시작하는게 더 빠른 경우
        {
            answer += name[index] - 'A';
        }

        if (nickname == name) // 바꾼 닉네임을 반영했으니 만약 동일하다면 break
            break;

        for (int i = 1; i < name.length(); i++)
        {
            if (name[(index + i) % name.length()] != nickname[(index + i) % name.length()])
            {
                index = (index + i) % name.length();
                answer += i;
                break;
            }
            else if(name[(index + name.length() - i) % name.length()] 
                != nickname[(index + name.length() - i) % name.length()])
            {
                index = (index + name.length() - i) % name.length();
                answer += i;
                break;
            }
        }
    }


    return answer;
}

int main()
{
    string name = "abc";

    cout << solution("JAN") << endl;
}