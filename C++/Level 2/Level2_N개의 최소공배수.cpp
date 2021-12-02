#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {

    int testNum = 0;

    while (true)
    {
        testNum++;
        vector<bool> tmp(arr.size(), false);

        for (int i = 0; i < arr.size(); i++)
        {
            if (testNum % arr[i] == 0)
                tmp[i] = true;
        }

        if (find(tmp.begin(), tmp.end(), false) == tmp.end())
            break;
    }

    return testNum;
}


void main()
{
    cout << solution({ 1,2,3 });
}

