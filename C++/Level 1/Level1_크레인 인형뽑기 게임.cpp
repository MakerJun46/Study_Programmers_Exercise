#include <vector>
#include <string>

using namespace std;

void checkpop(vector<int>& st, int& answer) {
	if (st.size() < 2) return;

	bool pop = false;
	vector<int> copy;

	for (int i = 1; i < st.size(); i++) {
		if (st[i] == st[i - 1]) {

			//int temp = i;
			//st.erase(st.begin()+ i - 1, st.begin() + i+1);

			st[i] = st[i - 1] = -1;
			answer = answer + 2;
			pop = true;
			break;
		}
	}

	for (auto i : st)
	{
		if (i == -1) continue;
		copy.push_back(i);
	}
	//cout << copy.size();
	st = copy;

	if (pop) checkpop(st, answer);
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	int size = board.size();

	vector<int> st;

	for (int i = 0; i < moves.size(); i++) {
		int tongs = moves[i] - 1;
		for (int j = 0; j < size; j++) {
			if (board[j][tongs] != 0) {
				st.push_back(board[j][tongs]);
				checkpop(st, answer);
				board[j][tongs] = 0;
				break;
			}
		}
	}
	return answer;
}