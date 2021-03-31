#include <vector>
#include <iostream>
#include "library.h"

using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    // 에라토스테네스의 체
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int solution(vector<int> nums) {

    sort(nums.begin(), nums.end());
    map<vector<int>, int> result;
    vector<int> tmp;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                tmp.push_back(nums[k]);
                
                if (isPrime(tmp[0] + tmp[1] + tmp[2]))
                {
                    sort(tmp.begin(), tmp.end());
                    result.insert(make_pair(tmp, tmp[0] + tmp[1] + tmp[2]));
                }

                tmp.clear();
            }
        }
    }
    
    return result.size();
}

int main() {

    cout << solution({ 1,2,3,4 }) << endl;
    cout << solution({ 1,6,0 }) << endl;
    cout << solution({ 1,2,7,6,4 }) << endl;

    return 0;
}