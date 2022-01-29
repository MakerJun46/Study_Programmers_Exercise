#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> report_users;
    vector<pair<string, string>> reported_log;

    string tmp;

    for (int i = 0; i < report.size(); i++)
    {
        vector<string> vec_tmp;

        stringstream ss(report[i]);
        while (getline(ss, tmp, ' '))
        {
            vec_tmp.push_back(tmp);
        }

        auto p = make_pair(vec_tmp[0], vec_tmp[1]);

        if (find(reported_log.begin(), reported_log.end(), p) == reported_log.end())
        {
            reported_log.push_back(p);
            report_users[vec_tmp[1]]++;
        }
    }

    for (auto i : reported_log)
    {
        if (report_users[i.second] >= k)
        {
            vector<string>::iterator it = find(id_list.begin(), id_list.end(), i.first);
            int index = it - id_list.begin();

            answer[index]++;
        }
    }

    return answer;
}

int main()
{
    vector<int> answer;

    //nswer = solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
    answer = solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);


    for (auto i : answer)
    {
        cout << i << endl;
    }
}