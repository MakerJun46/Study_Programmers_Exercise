#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    for (int i = 0; i <= 9; i++)
    {
        auto n_it = find(numbers.begin(), numbers.end(), i);
        if (n_it == numbers.end())
        {
            answer += i;
        }
    }

    return answer;
}


/* best answer
using namespace std;

int solution(vector<int> numbers) {
    return 45 - accumulate(numbers.begin(), numbers.end(), 0); // numebrs의 숫자를 모두 더한 후 45에서 빼기
} 
*/