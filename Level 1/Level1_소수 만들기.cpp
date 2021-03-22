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

    map<vector<int>, int> result;
    vector<int> vecTemp;
    
    sort(nums.begin(), nums.end());

    do {
        int temp = 0;
        for (int i = 0; i < 3; i++) 
        {
            vecTemp.push_back(nums[i]);
            temp += nums[i];
        }
        sort(vecTemp.begin(), vecTemp.end());
        if (isPrime(temp))
        {
            cout << "여기";
            result.insert(make_pair(vecTemp, temp));
        }
        vecTemp.clear();
    } while (next_permutation(nums.begin(), nums.end()));
    
    return result.size();
}

int main() {

    cout << solution({ 1,2,3,4 }) << endl;
    cout << solution({ 1,2,7,6,4 }) << endl;

    return 0;
}