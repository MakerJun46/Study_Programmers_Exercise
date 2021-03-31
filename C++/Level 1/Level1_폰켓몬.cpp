#include <vector>
#include "library.h"
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int species = unique(nums.begin(), nums.end()) - nums.begin();
    
    if (species > nums.size() / 2)
        return nums.size() / 2;
    else
        return species;
}


int main()
{
    cout << solution({ 3,3,1,2 });
    cout << solution({ 3,3,3,2,2,4 });
    cout << solution({ 3,3,3,2,2,2 });

    return 0;
}



/* Best Aanswer
* #include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}

*/