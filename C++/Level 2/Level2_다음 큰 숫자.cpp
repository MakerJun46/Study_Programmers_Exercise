#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int tmp = n;

    while (true)
    {
        tmp++;

        bitset<100> bs_tmp(tmp);
        bitset<100> bs_n(n);
        
        string s_tmp = bs_tmp.to_string();
        string s_n = bs_n.to_string();

        s_tmp = s_tmp.substr(s_tmp.find('1'));
        s_n = s_n.substr(s_n.find('1'));

        int s_tmp_count = 0;
        int s_n_count = 0;

        for (char c : s_tmp)
            if (c == '1')
                s_tmp_count++;

        for (char c : s_n)
            if (c == '1')
                s_n_count++;

        if (s_tmp_count == s_n_count)
        {
            answer = tmp;
            break;
        }
    }

    return answer;
}


int main()
{
    cout << solution(78) << endl;
}