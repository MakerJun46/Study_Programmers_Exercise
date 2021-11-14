#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < query.size(); i++)
    {
        int answerCount = 0;
        istringstream query_stream(query[i]);
        vector<string> this_query;
        string temp;
        while (getline(query_stream, temp, ' '))
        {
            if (temp == "and")
                continue;
            this_query.push_back(temp);
        }

        for (int j = 0; j < info.size(); j++)
        {
            bool isFind = true;

            string score = "";
            for (auto it = info[j].end() - 1; *it != ' '; it--)
            {
                score += *it;
            }
            reverse(score.begin(), score.end());


            if (stoi(score) < stoi(this_query.back()))  // 점수 조건 미달이면 바로 탈락
            {
                continue;
            }

            for (int k = 0; k < this_query.size() - 1; k++) // 조건에 맞는 사람 탐색 
            {
                if (this_query[k] == "-")
                    continue;
                else if (info[j].find(this_query[k]) == string::npos)    // 정보에서 조건을 못찾으면(조건 부합당) 패스
                {
                    isFind = false;
                    break;
                }
            }
            if (isFind)
            {
                answerCount++;
            }
        }

        answer.push_back(answerCount);
    }

    return answer;
}

int main()
{
    vector<string> info = { "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50" };

    vector<string> query = { "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150" };


    vector<int> answer = solution(info, query);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}