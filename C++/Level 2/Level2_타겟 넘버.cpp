#include <string>
#include <vector>

#include <iostream>
using namespace std;

int answer = 0;

void find_target_number(vector<int> numbers, int target, int sum, int index)
{
    if (index == numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }

    find_target_number(numbers, target, sum + numbers[index], index + 1);
    find_target_number(numbers, target, sum - numbers[index], index + 1);
}


int solution(vector<int> numbers, int target) {
    
    find_target_number(numbers, target, 0, 0);

    return answer;
}

int main()
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;
    
    cout << solution(numbers, target);
}