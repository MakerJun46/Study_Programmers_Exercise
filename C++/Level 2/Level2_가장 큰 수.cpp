#include <string>
#include <vector>
#include "library.h"

using namespace std;

bool cmpFirst(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first > b.first;
}

bool cmpSecond(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.second > b.second;
}

string solution(vector<int> numbers) {
	string answer = "";

    long long maxFront;
    long long maxBack;
	
    vector<pair<long long, long long>> MaxnumVec;

    sort(numbers.begin(), numbers.end());

    for (auto i : numbers)
    {
        answer += to_string(i);
    }


    do
    {
        string tempFront = "";
        string tempBack = "";
        for (int i = 0; tempFront.length() < answer.length() / 2; i++)
        {
            tempFront += to_string(numbers[i]);
        }

        for (int i = numbers.size(); i < numbers.size(); i++)
        {
            tempBack += to_string(numbers[i]);
        }

        MaxnumVec.push_back(pair<long long, long long>(stoll(tempFront), stoll(tempBack)));

    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(MaxnumVec.begin(), MaxnumVec.end(), cmpFirst);

    bool ismaxnumFront = true;
    long long maxnumFront = MaxnumVec[0].first;
    for (int i = 0; i < MaxnumVec.size() && ismaxnumFront; i++)
    {
        if (maxnumFront != MaxnumVec[i].first)
        {
            MaxnumVec.erase(MaxnumVec.begin() + i, MaxnumVec.end());
            ismaxnumFront = false;
        }
    }
    sort(MaxnumVec.begin(), MaxnumVec.end(), cmpSecond);

    answer = to_string(MaxnumVec.at(0).first) + to_string(MaxnumVec.at(0).second);
		
	return answer;
}

int main() {

    cout << solution({3,30,34,5,9});

	return 0;
}