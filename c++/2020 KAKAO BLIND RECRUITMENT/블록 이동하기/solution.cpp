#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>




using namespace std;

int solution(vector<vector<int>> board) {
	int answer = 100000;
	int n = board.size();
	queue<vector<int>>q;
	board[0][0] = -1;
	board[0][1] = -1;
	q.push({ 0,0,0,1,0 });
	set<vector<int>>s;
	s.insert({ 0,0,0,1 });
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		int a_x = f[0];
		int a_y = f[1];
		int b_x = f[2];
		int b_y = f[3];
		int time = f[4];
		if (b_y == n - 1 && b_x == n - 1) {
			answer = min(answer, time);
			continue;
		}
		time += 10;
		if (b_y - a_y == 1) {
			if (b_y + 1 < n&&board[b_x][b_y + 1] != 1 && s.find({ b_x,b_y,b_x,b_y + 1 }) == s.end()) {

				q.push({ b_x,b_y,b_x,b_y + 1,time });
				s.insert({ b_x,b_y,b_x,b_y + 1 });
			}
			if (a_y - 1 >= 0 && board[a_x][a_y - 1] != 1 && s.find({ a_x,a_y - 1,a_x,a_y }) == s.end()) {

				q.push({ a_x,a_y - 1,a_x,a_y,time });
				s.insert({ a_x,a_y - 1,a_x,a_y });
			}
			if (b_x + 1 < n&&board[b_x + 1][b_y] != 1 && (board[a_x + 1][a_y] != 1)) {
				if (s.find({ a_x,a_y ,a_x + 1,a_y }) == s.end()) {

					q.push({ a_x ,a_y,a_x + 1,a_y,time });
					s.insert({ a_x,a_y ,a_x + 1,a_y });

				}
				if (s.find({ b_x ,b_y,b_x + 1,b_y }) == s.end()) {

					q.push({ b_x ,b_y,b_x + 1,b_y,time });
					s.insert({ b_x ,b_y,b_x + 1,b_y });
				}
				if (s.find({ a_x + 1 ,a_y,b_x + 1,b_y }) == s.end()) {

					q.push({ a_x + 1 ,a_y,b_x + 1,b_y,time });
					s.insert({ a_x + 1 ,b_y,b_x + 1,b_y });
				}
			}
			if (b_x - 1 >= 0 && a_x - 1 >= 0 && board[b_x - 1][b_y] != 1 && board[a_x - 1][a_y] != 1) {
				if (s.find({ a_x - 1 ,a_y,a_x,a_y }) == s.end()) {

					q.push({ a_x - 1 ,a_y,a_x,a_y,time });
					s.insert({ a_x - 1 ,a_y,a_x,a_y });
				}
				if (s.find({ b_x - 1 ,b_y,b_x,b_y }) == s.end()) {

					q.push({ b_x - 1 ,b_y,b_x,b_y,time });
					s.insert({ b_x - 1 ,b_y,b_x,b_y });
				}
				if (s.find({ a_x - 1 ,a_y,b_x - 1 ,b_y }) == s.end()) {

					q.push({ a_x - 1 ,a_y,b_x - 1,b_y,time });
					s.insert({ a_x - 1 ,b_y,b_x - 1 ,b_y });
				}
			}

		}
		if (b_x - a_x == 1) {
			if (b_x + 1 < n&&board[b_x + 1][b_y] != 1 && s.find({ b_x,b_y,b_x + 1,b_y }) == s.end()) {

				q.push({ b_x,b_y,b_x + 1,b_y ,time });
				s.insert({ b_x,b_y,b_x + 1,b_y });
			}
			if (a_x - 1 >= 0 && board[a_x - 1][a_y] != 1 && s.find({ a_x - 1,a_y ,a_x,a_y }) == s.end()) {

				q.push({ a_x - 1,a_y ,a_x,a_y,time });
				s.insert({ a_x - 1,a_y ,a_x,a_y });
			}
			if (b_y + 1 < n&&board[b_x][b_y + 1] != 1 && board[a_x][a_y + 1] != 1) {
				if (s.find({ a_x ,a_y,a_x,a_y + 1 }) == s.end()) {

					q.push({ a_x ,a_y,a_x,a_y + 1,time });
					s.insert({ a_x ,a_y,a_x,a_y + 1 });
				}
				if (s.find({ b_x ,b_y,b_x,b_y + 1 }) == s.end()) {

					q.push({ b_x ,b_y,b_x,b_y + 1,time });
					s.insert({ b_x ,b_y,b_x,b_y + 1 });
				}
				if (s.find({ a_x ,a_y + 1,b_x ,b_y + 1 }) == s.end()) {

					q.push({ a_x ,a_y + 1,b_x ,b_y + 1,time });
					s.insert({ a_x ,a_y + 1,b_x,b_y + 1 });
				}
			}
			if (a_y - 1 >= 0 && b_y - 1 >= 0 && board[b_x][b_y - 1] != 1 && board[a_x][a_y - 1] != 1) {
				if (s.find({ a_x ,a_y - 1,a_x,a_y }) == s.end()) {

					q.push({ a_x ,a_y - 1,a_x,a_y,time });
					s.insert({ a_x ,a_y - 1,a_x,a_y });
				}
				if (s.find({ b_x ,b_y - 1,b_x,b_y }) == s.end()) {

					q.push({ b_x ,b_y - 1,b_x,b_y,time });
					s.insert({ b_x ,b_y - 1,b_x,b_y });
				}
				if (s.find({ a_x ,a_y - 1,b_x ,b_y - 1 }) == s.end()) {

					q.push({ a_x ,a_y - 1,b_x ,b_y - 1,time });
					s.insert({ a_x ,a_y - 1,b_x,b_y - 1 });
				}
			}

		}
	}

	return answer / 10;
}