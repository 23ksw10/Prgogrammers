#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	for (auto a : moves) {
		for (int i = 0; i < board.size(); i++) {
			if (!board[i][a - 1]) continue;
			else {
				if (s.size() > 0 && s.top() == board[i][a - 1]) {
					answer++;
					s.pop();
				}
				else s.push(board[i][a - 1]);
				board[i][a - 1] = 0;
				break;
			}
		}


	}
	return answer * 2;
}