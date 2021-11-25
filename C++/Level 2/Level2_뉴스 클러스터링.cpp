#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    if (str1 == "" && str2 == "" || str1 == str2)
        return 65536;

    vector<string> str1_vec;
    vector<string> str2_vec;

    for (int i = 0; i < str1.length() - 1; i++)
    {
        string tmp = "";
        
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            tmp += str1[i];
            tmp += str1[i + 1];
            str1_vec.push_back(tmp);
        }
    }

    for (int i = 0; i < str2.length() - 1; i++)
    {
        string tmp = "";

        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            tmp += str2[i];
            tmp += str2[i + 1];
            str2_vec.push_back(tmp);
        }
    }

    sort(str1_vec.begin(), str1_vec.end());
    sort(str2_vec.begin(), str2_vec.end());
    
    vector<string> str_union(str1_vec.size() + str2_vec.size());
    vector<string> str_intersection(str1_vec.size() + str2_vec.size());

    auto it_union = set_union(str1_vec.begin(), str1_vec.end(), str2_vec.begin(), str2_vec.end(), str_union.begin());
    str_union.erase(it_union, str_union.end());

    auto it_intersection = set_intersection(str1_vec.begin(), str1_vec.end(), str2_vec.begin(), str2_vec.end(), str_intersection.begin());
    str_intersection.erase(it_intersection, str_intersection.end());

    return (int)(float)str_intersection.size() / (float)str_union.size() * 65536.0;
}


int main()
{
    string str1 = "france";
    string str2 = "french";

    cout << solution(str1, str2) << endl;
}