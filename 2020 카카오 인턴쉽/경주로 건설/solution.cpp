#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
	int i[4] = { -1,0,1,0 };
	int j[4] = { 0,1,0,-1 };
	int answer = 100000000;
	int n = board.size();
	vector<int>v;
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {0,0},{-1,0} });
	board[0][0] = 1;
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		if (a.first.first == n - 1 && a.first.second == n - 1) {
			answer = min(a.second.second, answer);
			continue;
		}
		for (int k = 0; k < 4; k++) {
			int x = a.first.first + i[k];
			int y = a.first.second + j[k];
			if (x < 0 || x >= n || y >= n || y < 0 || board[x][y] == 1)continue;
			int coast;
			if (k == a.second.first || a.second.first == -1) {
				coast = a.second.second + 100;

			}
			else if (k != a.second.first) {
				coast = a.second.second + 600;

			}
			if (board[x][y] >= coast || board[x][y] == 0) {
				board[x][y] = coast;
				q.push({ {x,y},{k,coast} });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return answer;
}