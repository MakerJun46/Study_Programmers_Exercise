#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int calcTime(string inTime, string outTime)
{
    int remainHour = stoi(outTime.substr(0, 2)) - stoi(inTime.substr(0, 2));;
    int inTimeMinute = stoi(inTime.substr(3, 2));
    int outTimeMinute = stoi(outTime.substr(3, 2));
    int remainMinute = outTimeMinute - inTimeMinute;

    if (remainMinute < 0)
    {
        remainHour--;
        remainMinute += 60;
    }

    return remainHour * 60 + remainMinute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> numberAndFees;
    map<string, string> inNumberAndTimes;

    for (int i = 0; i < records.size(); i++)
    {
        vector<string> timeAndNumberTmp;
        string tmp;
        stringstream ss(records[i]);

        while (getline(ss, tmp, ' '))
        {
            timeAndNumberTmp.push_back(tmp);
        }

        if (timeAndNumberTmp[2] == "IN")
        {
            inNumberAndTimes[timeAndNumberTmp[1]] = timeAndNumberTmp[0];
        }
        else
        {
            int remainTime = calcTime(inNumberAndTimes[timeAndNumberTmp[1]], timeAndNumberTmp[0]);
            numberAndFees[timeAndNumberTmp[1]] += remainTime;
            inNumberAndTimes.erase(timeAndNumberTmp[1]);
        }
    }

    if (!inNumberAndTimes.empty())
    {
        for (auto i : inNumberAndTimes)
        {
            int remainTime = calcTime(i.second, "23:59");
            numberAndFees[i.first] += remainTime;
        }
    }

    for (auto i : numberAndFees)
    {
        if (i.second <= fees[0]) // normal fee under 180 minute
        {
            numberAndFees[i.first] = fees[1];
        }
        else
        {
            numberAndFees[i.first] = fees[1] + ((i.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
        }

        answer.push_back(numberAndFees[i.first]);
    }

    return answer;
}

int main()
{/*
    vector<int> answer = solution({ 180, 5000, 10, 600 },
        { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
        "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
        "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });*/

    vector<int> answer2 = solution({ 1, 461, 1, 10 },
        { "00:00 1234 IN" });
}