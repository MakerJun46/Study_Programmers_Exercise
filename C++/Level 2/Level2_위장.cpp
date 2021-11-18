#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 1번옷 종류의 개수 x 2번 옷 종류의 개수....n번 옷 종류의 개수 + 1번 옷 종류의 개수 + 2번옷..

// 안입는 경우 -> 하나의 옵션으로 생각
// 다 안입을 수는 없으니까 최종 경우에서 -1

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	
	map<string, int> clothes_sort;

	for (auto this_cloth : clothes)
	{
		if (clothes_sort.find(this_cloth[1]) != clothes_sort.end()) // 이미 들어간 경우
		{
			clothes_sort.find(this_cloth[1])->second++;
		}
		else // 아직 안들어간 경우
		{
			clothes_sort.insert(make_pair(this_cloth[1], 1));
		}
	}

	for (auto count : clothes_sort)
	{
		if (answer == 0)
			answer++;
		answer *= count.second + 1; // 안입는 경우를 +1로 생각
	}

	answer--; // 모두 안입는 경우는 없으니까

	return answer;
}


int main()
{
	vector<vector<string>> clothes =
	{ {"crowmask", "face"},
		{"bluesunglasses", "face" },
		{"smoky_makeup", "face" } };

	cout << "답은 : " << solution(clothes) << endl;

}


/* best answer ==>
int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map <string, int> attributes;
	for(int i = 0; i < clothes.size(); i++)
		attributes[clothes[i][1]]++;
	for(auto it = attributes.begin(); it != attributes.end(); it++)
		answer *= (it->second+1);
	answer--;

	return answer;
}

*/