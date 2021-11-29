#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> setMenu;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

void add_combination(string n, int r)
{
    vector<bool> temp(n.length(), false);

    for (int i = 0; i < r; i++)
    {
        temp[i] = true;
    }
    do
    {
        string this_combination = "";
        for (int i = 0; i < n.length(); i++)
        {
            if (temp[i])
                this_combination += n[i];
        }

        setMenu[this_combination]++;

    } while (prev_permutation(temp.begin(), temp.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;


    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());

        for (int j = 0; j < course.size(); j++)
        {
            if (orders[i].length() < course[j])
                break;
            add_combination(orders[i], course[j]);
        }
    }

    vector<pair<string, int>> setMenu_vec(setMenu.begin(), setMenu.end());

    for (int i = 0; i < course.size(); i++)
    {
        vector<pair<string, int>> tmp;
        for (int j = 0; j < setMenu_vec.size(); j++)
        {
            if (setMenu_vec[j].first.length() == course[i] && setMenu_vec[j].second > 1)
                tmp.push_back(setMenu_vec[j]);
        }
        if (!tmp.empty())
        {
            sort(tmp.begin(), tmp.end(), cmp);
            int max_count = tmp[0].second;

            for (int j = 0; j < tmp.size(); j++)
            {
                if (max_count == tmp[j].second)
                    answer.push_back(tmp[j].first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };

    vector<string> answer = solution(orders, course);

    for (auto i : answer)
    {
        cout << i << endl;
    }
}