#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {

    map<string, bool> m;

    for (auto i : phone_book)
    {
        m[i] = true;
    }

    for (auto number : phone_book)
    {
        string tmp = "";
        for (int i = 0; i < number.length(); i++)
        {
            tmp += number[i];
            if (m[tmp] && tmp != number)
            {
                return false;
            }
        }
    }

    return true;
}


void main()
{
    vector<string> pb = { "119", "97674223", "1195524421" };
    vector<string> pb2 = { "123", "456", "789" };

    cout << solution(pb) << endl;
    cout << solution(pb2) << endl;
    
}