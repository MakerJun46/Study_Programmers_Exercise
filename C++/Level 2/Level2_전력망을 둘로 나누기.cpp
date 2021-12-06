#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int>> connectMap;
vector<bool> visited;

int connectCount(int towerNumber)
{
	int count = 1;
	visited[towerNumber] = true;

	if (connectMap[towerNumber].empty())
		return 1;

	for (int i = 0; i < connectMap[towerNumber].size(); i++)
	{
		if (!visited[connectMap[towerNumber][i]])
			count += connectCount(connectMap[towerNumber][i]);
	}

	return count;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = n;

	for (auto w : wires)
	{
		connectMap[w[0]].push_back(w[1]);
		connectMap[w[1]].push_back(w[0]);
	}
	
	auto tmp = connectMap;

	for (auto w : wires)
	{
		connectMap = tmp;
		visited.assign(n + 1, false);

		connectMap[w[0]].erase(find(connectMap[w[0]].begin(), connectMap[w[0]].end(), w[1]));
		connectMap[w[1]].erase(find(connectMap[w[1]].begin(), connectMap[w[1]].end(), w[0]));

		int min_abs = abs(connectCount(w[0]) - connectCount(w[1]));

		if (answer > min_abs)
			answer = min_abs;
	}

	return answer;
}

void main()
{
	vector<vector<int>> wires
	{
		{1, 3},
		{2, 3},
		{3, 4},
		{4, 5},
		{4, 6},
		{4, 7},
		{7, 8},
		{7, 9},
	};
	int n = 9;

	cout << solution(n, wires) << endl;
}
