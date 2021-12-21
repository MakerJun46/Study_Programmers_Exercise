#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> quad_Tree(vector<vector<int>> arr, int n)
{
	vector<int> returnVec(2, 0);

	if (n == 0)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			returnVec[arr[i][0]]++;
		}
		return returnVec;
	}

	int zeroOrOne = arr[0][0];
	bool isCorrect = true;
	for (int i = 0; i < arr.size(); i++)		// 사각형이 1개의 숫자로 이루어져 있는지 체크
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] != zeroOrOne)
			{
				isCorrect = false;
				break;
			}
		}
	}

	if (isCorrect)	// 맞으면 바로 return
	{
		returnVec[zeroOrOne]++;
		return returnVec;
	}

	for (int k = 0; k < 2; k++)
	{
		vector<vector<int>> rect1;
		vector<vector<int>> rect2;

		for (int i = k * n; i < k * n + n; i++)	// 아니면 사각형 분할해서 재귀 호출
		{
			vector<int> left{ arr[i].begin(), arr[i].begin() + n };
			vector<int> right{ arr[i].begin() + n, arr[i].end() };

			rect1.push_back(left);
			rect2.push_back(right);
		}
		vector<int> returnLeft = quad_Tree(rect1, n / 2);
		vector<int> returnRight = quad_Tree(rect2, n / 2);

		returnVec[0] += returnLeft[0] + returnRight[0];
		returnVec[1] += returnLeft[1] + returnRight[1];
	}

	return returnVec;
}

vector<int> solution(vector<vector<int>> arr) {
	int n = arr.size();

	return quad_Tree(arr, n / 2);
}

int main()
{
	vector<vector<int>> arr1
	{
		{1, 1, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
	};

	vector<vector<int>> arr2
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1, 1, 1, 1},
		{0, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0 ,0, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 1, 1, 1, 1}
	};

	vector<int>answer = solution(arr2);

	for (auto i : answer)
	{
		cout << i << endl;
	}
}