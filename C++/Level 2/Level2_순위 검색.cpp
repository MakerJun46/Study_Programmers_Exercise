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
        istringstream query_stream(query[i]);
        vector<string> this_query;
        string temp;
        while (getline(query_stream, temp, ' '))
        {
            this_query.push_back(temp);
        }

        for (int i = 0; i < this_query.size(); i++)
        {
            cout << this_query[i] << endl;
        }
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
    vector<string> query = { "java and backend and junior and pizza 100"
        ,"python and frontend and senior and chicken 200",
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