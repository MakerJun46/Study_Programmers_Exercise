#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string change_sharp(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '#')
            s[i] = tolower(s[i - 1]);
    }

    return s;
}

int playTime(string start, string end)
{
    int hour = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    int minute;

    if (hour == 0)
        minute = stoi(end.substr(3, 5)) - stoi(start.substr(3, 5));
    else
    {
        hour--;
        minute = 60 - stoi(start.substr(3, 5)) + stoi(end.substr(3, 5));
    }

    return hour * 60 + minute;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int music_playTime = 0;

    for (int i = 0; i < musicinfos.size(); i++)
    {
        stringstream ss(musicinfos[i]);
        vector<string> tmp;
        string s;
        while (getline(ss, s, ','))
        {
            tmp.push_back(s);
        }

        int this_playTime = playTime(tmp[0], tmp[1]);
        int playTime_tmp = this_playTime;

        tmp[3] = change_sharp(tmp[3]);
        m = change_sharp(m);

        s = "";
        int index = 0;
        for (int j = 0; j < playTime_tmp; j++)
        {
            char c = tmp[3][index % tmp[3].length()];
            char next_c = tmp[3][(index + 1) % tmp[3].length()];
            
            s += c;

            if (islower(next_c))
            {
                s += next_c;
                index++;
            }
            
            index++;
        }

        vector<int> positions;
        int pos = s.find(m, 0);
        while (pos != string::npos)
        {
            positions.push_back(pos);
            pos = s.find(m, pos + 1);
        }

        for (auto p : positions)
        {
            if (!islower(s[p + m.length()]) && music_playTime < this_playTime)
            {
                answer = tmp[2];
                music_playTime = this_playTime;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> musicinfos
    {
        "13:00,13:06,WORLD,ABCDEF"
    };

    cout << solution("E", musicinfos) << endl;
}