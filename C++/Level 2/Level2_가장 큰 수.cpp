#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isNotZero(string n) 
{
    return n != "0";
}

bool cmp(string a, string b) {
    a += a;
    b += b;

    bool isABigThanB = a.length() > b.length();

    if(isABigThanB) // a.length() > b.length()
    {
        int size = a.length() - b.length();
        int bLength = b.length();

        for (int i = 0; i < size; i++)
        {
            b += b[i % bLength];
        }
    }
    else
    {
        int size = b.length() - a.length();
        int aLength = a.length();

        for (int i = 0; i < size; i++)
        {
            a += a[i % aLength];
        }
    }

    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> numStr;
    string answer = "";

    for (auto i : numbers)
    {
        numStr.push_back(to_string(i));
    }

    sort(numStr.begin(), numStr.end(), cmp);

    if (find_if(numStr.begin(), numStr.end(), isNotZero) == numStr.end())
        return "0";

    for (auto i : numStr)
    {
        answer += i;
    }

    return answer;
}

int main() {
    
    cout << solution({ 6, 10, 2 }) << endl;
    cout << solution({ 0,0,0,0 }) << endl;
    cout << solution({ 21,212, 21 }) << endl;
    cout << solution({ 1000, 0, 5, 99, 100 }) << endl;
    cout << solution({ 402212, 12 }) << endl;
    cout << solution({ 40, 404 }) << endl;
    

    cout << solution({ 10,0,0,1,2,3,4,5,6,7,8,9,10});

    return 0;
}


/*  BestAnswer
bool compare(const string &a, const string &b)
{
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter;

    if (answer[0] == '0')
        answer = "0";

    return answer;
}
*/