#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    int index = 0;

    if(s.length() % 2 == 1){
        index = (s.length() - 1) / 2;
        answer = s[index];
    }
    else {
        index = s.length() / 2 - 1;
        answer = s[index];
        index++;
        answer += s[index];
    }


    return answer;
}

/* Best answer
#include <string>

using namespace std;

string solution(string s) {
    return s.length()&1 ? s.substr(s.length()*0.5,1) : s.substr(s.length()*0.5-1,2);
}  // s.length()&1 ==> s.length() 문자열 길이가 홀수라면 비트 2진법 마지막 수가 1이므로 비트 연산자
   // &1 연산 시 1(참)이 되고, 짝수라면 2진법 마지막 수가 반드시 0이므로 0(거짓)이 된다.. 똑똑한 코드 
*/


int main() {

    cout << &5;

    return 0;
}