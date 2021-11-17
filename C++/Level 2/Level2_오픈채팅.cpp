#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>


// 유저 아이디로만 answer 에 추가하고
// 나중에 치환하는 방식으로
// 어차피 마지막 닉네임으로만 표시되니까 유저 아이디랑 마지막 닉네임만 알면됨

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id;

    for (int i = 0; i < record.size(); i++)
    {
        istringstream query(record[i]);
        string order, user, nickname;
        getline(query, order, ' ');
        getline(query, user, ' ');
        getline(query, nickname, ' ');

        switch (record[i][0])
        {
        case 'E':
            answer.push_back(user + " 님이 들어왔습니다.");
            if (id.find(user) != id.end())
            {
                id.find(user)->second = nickname;
            }
            else
            {
                id.insert(make_pair(user, nickname));
            }
            break;
        case 'L':
            answer.push_back(user + " 님이 나갔습니다.");
            break;
        case 'C':
            if (id.find(user) != id.end())
            {
                id.find(user)->second = nickname;
            }
            else
            {
                id.insert(make_pair(user, nickname));
            }
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        istringstream  changeNick(answer[i]);
        string userId;
        getline(changeNick, userId, ' ');
        auto it = id.find(userId);
        answer[i].replace(answer[i].find(userId), userId.length() + 1, it->second);
    }

    return answer;
}

void main()
{
    vector<string> record = { "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan" };

    vector<string> answer = solution(record);

    
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    
}