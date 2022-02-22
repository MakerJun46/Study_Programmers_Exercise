#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool file_sort_func(vector<string>& A, vector<string>& B)
{
    if (A[0] != B[0]) // cmp Head
    {
        return A[0] < B[0];
    }
    else if (stoi(A[1]) != stoi(B[1])) // cmp number
    {
        return stoi(A[1]) < stoi(B[1]);
    }
    else
    {
        return stoi(A[2]) < stoi(B[2]); // cmp input order
    }

    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<vector<string>> file_splits;

    for (int i = 0; i < files.size(); i++)
    {
        string head_tmp = "";
        string number_tmp = "";
        string tail_tmp;
        string this_file = files[i];
        int index = 0;

        while (true)    // split head
        {
            if (isdigit(this_file[index]))
                break;

            head_tmp += toupper(this_file[index]);
            index++;
        }

        while (true) // split number
        {
            if (!isdigit(this_file[index]) || number_tmp.length() == 5)
                break;

            number_tmp += this_file[index];
            index++;
        }

        tail_tmp = to_string(i); // if head and numbers are same, compare input order

        file_splits.push_back({ head_tmp, number_tmp, tail_tmp });
    }

    sort(file_splits.begin(), file_splits.end(), file_sort_func);

    for (int i = 0; i < file_splits.size(); i++)
    {
        answer.push_back(files[stoi(file_splits[i][2])]);
    }

    return answer;
}


int main()
{
    vector<string> answer = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });

    for (auto c : answer)
    {
        cout << c << endl;
    }
}

/* best answer
char makeLower(char c)
{
    if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    return c;
}
int findNumIdx(const string &str)
{
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}
int getNumber(string str)
{
    return std::stoi(str.substr( findNumIdx(str) ));
}
string getHeader(string str)
{
    string rtn = str.substr(0, findNumIdx(str));

    std::transform(rtn.begin(), rtn.end(), rtn.begin(), makeLower);

    return rtn;
}

bool numComp(string str1, string str2) { return getNumber(str1) < getNumber(str2); }
bool headComp(string str1, string str2) { return getHeader(str1).compare(getHeader(str2)) < 0; }

vector<string> solution(vector<string> files)
{
    std::stable_sort(files.begin(), files.end(), numComp);

    std::stable_sort(files.begin(), files.end(), headComp);

    return files;
}
*/