#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char OppositeChar(char c)
{
    switch (c)
    {
    case 'U':
        return 'D';
    case 'D':
        return 'U';
    case 'R' :
        return 'L';
    case 'L' :
        return 'R';
    }
}

int solution(string dirs) {
    int answer = 0;

    map<vector<int>, string> location;

    vector<int> tmp = { 0, 0 };
    vector<int> prev_loc = tmp;
    char prev_move = 'A';

    for (char c : dirs)
    {
        bool isMoved = true;

        if (c == 'U' && tmp[1] != 5)
            tmp[1]++;
        else if (c == 'D' && tmp[1] != -5)
            tmp[1]--;
        else if (c == 'R' && tmp[0] != 5)
            tmp[0]++;
        else if (c == 'L' && tmp[0] != -5)
            tmp[0]--;
        else
            isMoved = false;

        if (isMoved)
        {
            if (location[prev_loc].find(OppositeChar(c)) == string::npos)
            {
                location[tmp] += c;
            }
            prev_move = c;
            prev_loc = tmp;
        }
    }
    
    for (auto m : location)
    {
        m.second.erase(unique(m.second.begin(), m.second.end()), m.second.end());
        answer += m.second.length();
    }
    
    return answer;
}

int main()
{
    cout << solution("UUUUDUDUDUUU") << endl; // 5
}