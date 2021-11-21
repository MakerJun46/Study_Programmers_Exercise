#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> measure;

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            measure.push_back(i);
        }
    }

    for (auto height : measure)
    {
        if (height * 2 + (yellow / height) * 2 + 4 == brown)
        {
            answer.push_back(yellow / height + 2); // width
            answer.push_back(height + 2); // height
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> answer = solution(10, 2);
    
    for (auto i : answer)
    {
        cout << i << endl;
    }

}