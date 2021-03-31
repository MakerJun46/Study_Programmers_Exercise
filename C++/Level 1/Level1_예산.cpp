#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int tmp = 0;
    
    if (accumulate(d.begin(), d.end(), 0) <= budget) {
        answer = d.size();
    }
    else {
        sort(d.begin(), d.end());
        for (auto i : d) {
            tmp += i;
            if(tmp > budget){
                break;
            }
            answer++;
        }
    }

    return answer;
}

