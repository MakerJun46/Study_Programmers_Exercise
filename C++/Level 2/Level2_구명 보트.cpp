#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.rbegin(), people.rend());

    int index = people.size() - 1;

    for (int i = 0; i < people.size(); i++)
    {
        if (index <= i)
        {
            if (index == i)
                answer++;
            break;
        }
        else if (people[i] + people[index] <= limit)
        {
            index--;
        }
        answer++;
    }   
    return answer;
}

void main()
{
    //cout << solution({ 70, 50, 80, 50, 50 }, 100) << endl;
    //cout << solution({ 40, 50, 150, 160 }, 200) << endl;

    cout << solution({ 100, 500, 500, 900, 950 }, 1000) << endl;

}