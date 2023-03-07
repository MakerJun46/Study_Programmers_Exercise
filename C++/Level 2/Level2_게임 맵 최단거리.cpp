#include<vector>
#include <iostream>
#include <queue>
using namespace std;

bool visited[101][101];
int dist[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int solution(vector<vector<int> > maps)
{
	queue<pair<int, int>> q;
	bool isFind = false;

	q.push(make_pair(0, 0));
	dist[0][0] = 1;

	while (!q.empty())
	{
		auto item = q.front(); q.pop();


		for (int i = 0; i < 4; i++)
		{
			int n = item.first + dx[i];
			int m = item.second + dy[i];

			if (visited[n][m])
				continue;
			if (n < 0 || m < 0 || n > maps.size() - 1 || m > maps[0].size() - 1)
				continue;
			if (maps[n][m] == 0)
				continue;

			dist[n][m] = dist[item.first][item.second] + 1;

			q.push(make_pair(n, m));
			visited[n][m] = true;
		}
	}

	if (!visited[maps.size() - 1][maps[0].size() - 1])
		return -1;
	else
		return dist[maps.size() - 1][maps[0].size() - 1];
}

int main()
{
	cout << solution({ {1, 0, 1, 1, 1},
						{1, 0, 1, 0, 1},
						{1, 0, 1, 1, 1},
						{1, 1, 1, 0, 1},
						{0, 0, 0, 0, 1} });
}