#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);

	map<string, int> reportCount;
	set<pair<string, string>> reported_log;

	string tmp;

	for (int i = 0; i < report.size(); i++)
	{
		vector<string> vec_tmp;

		stringstream ss(report[i]);
		while (getline(ss, tmp, ' '))
		{
			vec_tmp.push_back(tmp);
		}

		auto p = make_pair(vec_tmp[0], vec_tmp[1]);

		if (reported_log.find(p) == reported_log.end())
		{
			reported_log.insert(p);
			reportCount[vec_tmp[1]]++;
		}
	}

	for (auto it = reported_log.begin(); it != reported_log.end(); it++)
	{
		if (reportCount[it->second] >= k)
		{
			answer.at(find(id_list.begin(), id_list.end(), it->first) - id_list.begin())++;
		}
	}

	return answer;
}

int main()
{
	//vector<int>answer = solution({ "con", "ryan" },
	//	{ "ryan con", "ryan con", "ryan con", "ryan con" }, 3);

	vector<int> answer2 = solution({ "muzi", "frodo", "apeach", "neo" },
		{ "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);

	for (auto i : answer2)
	{
		cout << i << endl;
	}
}